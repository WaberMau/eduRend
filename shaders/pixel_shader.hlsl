
Texture2D texDiffuse : register(t0);

cbuffer LightCamBuffer : register(b0) 
{
	float4 LPos : Light_Position;
	float4 CPos : Camera_Position;
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
	// Calculate light direction
	   float3 lightDir = normalize(LPos.xyz - input.PosWorld);

	   // Calculate view direction
	   float3 viewDir = normalize(CPos.xyz - input.PosWorld);

	   // Calculate reflection direction
	   float3 reflectDir = reflect(-lightDir, input.Normal);

	   // Calculate diffuse
	   float diffFactor = max(0.0f, dot(input.Normal, lightDir));

	   // Calculate specular
	   float specFactor = pow(max(0.0f, dot(reflectDir, viewDir)), 64);

	   // Combine diffuse and specular (no texture)
	   float4 finalColor = float4(diffFactor + specFactor, diffFactor + specFactor, diffFactor + specFactor, 1.0f);

	   //float4 finalColor = float4(diffFactor, diffFactor, diffFactor, 1.0f);

	   return finalColor;

	// Debug shading #1: map and return normal as a color, i.e. from [-1,1]->[0,1] per component
	// The 4:th component is opacity and should be = 1
	//return float4(input.Normal*0.5+0.5, 1);
	
	// Debug shading #2: map and return texture coordinates as a color (blue = 0)
//	return float4(input.TexCoord, 0, 1);
}