#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// own variables
uniform int tick;

// Output fragment color
out vec4 finalColor;

void main()
{
    vec2 texel = 1.0 / vec2(textureSize(texture0, 0));
    float t = mod(float(tick), (2 * 3.14159265359));
    finalColor = texture(texture0, fragTexCoord + vec2(cos(t), sin(t)) * texel) * colDiffuse * fragColor;
}
