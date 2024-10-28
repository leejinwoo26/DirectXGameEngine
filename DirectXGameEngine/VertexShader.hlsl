struct VSOut
{
    float3 color : Color;
    float4 pos : SV_Position;
};

cbuffer cBuf
{
    matrix transform;
};

VSOut main(float2 pos : position, float3 color : Color)
{
    VSOut vso;
    vso.pos = mul(float4(pos.x, pos.y, 0, 1), transform);
    vso.color = color;
    return vso;
}