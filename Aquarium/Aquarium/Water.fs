#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec2 TexCoords;
in vec3 Normal;

uniform sampler2D reflectionTexture;  
uniform sampler2D refractionTexture;
uniform sampler2D dudvMap;           
uniform sampler2D normalMap;  
uniform float time;                   
uniform vec3 lightPos;
uniform vec3 viewPos;

const float waveStrength = 0.02;
const float shineDamper = 20.0;
const float reflectivity = 0.5;

void main()
{
    vec2 distortedTexCoords = TexCoords + texture(dudvMap, TexCoords + vec2(0.0, time * 0.05)).rg * 0.1;
    distortedTexCoords = clamp(distortedTexCoords, 0.001, 0.999);

    vec4 reflectionColor = texture(reflectionTexture, distortedTexCoords);
    vec4 refractionColor = texture(refractionTexture, distortedTexCoords);

    vec3 normalTex = texture(normalMap, distortedTexCoords).rgb;
    normalTex = normalize(normalTex * 2.0 - 1.0);
    vec3 viewDir = normalize(viewPos - FragPos);
    float fresnelFactor = dot(viewDir, Normal);
    fresnelFactor = clamp(fresnelFactor, 0.0, 1.0);

    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(normalTex, lightDir), 0.0);

    vec3 reflectDir = reflect(-lightDir, normalTex);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shineDamper);
    vec3 specular = vec3(1.0) * spec * reflectivity;

    vec3 finalColor = mix(reflectionColor.rgb, refractionColor.rgb, fresnelFactor);
    finalColor = finalColor * diff + specular;

    finalColor = pow(finalColor, vec3(1.0 / 1.2));

    FragColor = vec4(finalColor, 1.0);
}
