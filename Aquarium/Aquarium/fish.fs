#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

uniform sampler2D texture_diffuse;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    
    vec3 diffuse = diff * lightColor;
    
    vec3 ambient = 0.1 * lightColor;
    
    vec3 result = (ambient + diffuse) * texture(texture_diffuse, TexCoords).rgb;
    FragColor = vec4(result, 1.0);
}
