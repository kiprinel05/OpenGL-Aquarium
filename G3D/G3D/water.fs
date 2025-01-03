#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture_diffuse1;

void main()
{
    vec4 texColor = texture(texture_diffuse1, TexCoords);
    FragColor = vec4(texColor.rgb * 0.5 + vec3(0.0, 0.5, 0.7) * 0.5, texColor.a);
}