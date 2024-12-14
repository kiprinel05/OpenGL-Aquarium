﻿#version 330 core

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform sampler2D texture_diffuse1;

out vec4 FragColor;

void main() {
    vec3 color = texture(texture_diffuse1, TexCoords).rgb;

    FragColor = vec4(color, 1.0);
}
