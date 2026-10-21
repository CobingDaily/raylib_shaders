#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

void main()
{
    vec2 texel = 1.0 / vec2(textureSize(texture0, 0));
    vec4 sum = vec4(0.0);

    int radius = 5;

    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            sum += texture(texture0, fragTexCoord + vec2(x, y) * texel);
        }
    }

    finalColor = (sum / pow(2 * radius + 1, 2.0)) * colDiffuse * fragColor;
}
