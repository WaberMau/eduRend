
Texture2D texDiffuse : register(t0);
SamplerState texSampler : register(s0);

cbuffer LightCamBuffer : register(b0) 
{
	float4 LPos : Light_Position;
	float4 CPos : Camera_Position;
}

cbuffer MaterialBuffer : register(b1)
{
	float4 Ambient;
	float4 Diffuse;
	float4 Specular;
}

struct PSIn
{
	float4 Pos  : SV_Position;
	float3 Normal : NORMAL;
	float2 TexCoord : TEX;
	float3 PosWorld : WORLD_POSITION;
};

//-----------------------------------------------------------------------------------------
// Pixel Shader
//-----------------------------------------------------------------------------------------

float4 PS_main(PSIn input) : SV_Target
{

	float3 L = normalize(LPos.xyz - input.PosWorld);

	float LN = max(0.0f, dot(input.Normal, L));

	float3 R = reflect(-L, input.Normal);

	float3 V = normalize(CPos.xyz - input.PosWorld);

	float  RV = pow(max(0.0f, dot(R, V)), Specular.w);

	//float4 I = Ambient + ((Diffuse * LN) + (Specular * RV));

	float4 I = Ambient * texDiffuse.Sample(texSampler, input.TexCoord) + 
		(((Diffuse * texDiffuse.Sample(texSampler, input.TexCoord)) * LN) + 
			((Specular * texDiffuse.Sample(texSampler, input.TexCoord)) * RV));

	return I;
	
	// Debug shading #2: map and return texture coordinates as a color (blue = 0)
//	return float4(input.TexCoord, 0, 1);
}