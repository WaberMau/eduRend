
Texture2D texDiffuse : register(t0);

cbuffer LightCamBuffer : register(b0) 
{
	float4 LPos : Light_Position;
	float4 CPos : Camera_Position;
}

cbuffer MaterialBuffer : register(b1)
{
	float4 Ambient : Ambient;
	float4 Diffuse : Diffuse;
	float4 Specular : Specular;
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

	//// Calculate light direction
	//   float3 lightDir = normalize(LPos.xyz - input.PosWorld);

	//   // Calculate view direction
	//   float3 viewDir = normalize(CPos.xyz - input.PosWorld);

	//   // Calculate reflection direction
	//   float3 reflectDir = reflect(-lightDir, input.Normal);

	//   // Calculate diffuse
	//   float diffFactor = max(0.0f, dot(input.Normal, lightDir) - Diffuse);
	//   //diffFactor -= 0.3f;

	//   //if (diffFactor < 0.0f)
	//	  // diffFactor = 0.0f;

	//   // Calculate specular
	//   float specFactor = pow(max(0.0f, dot(reflectDir, viewDir) - Specular), 32);

	//   // Combine diffuse and specular (no texture)
	//   float4 finalColor = float4(Ambient + (diffFactor + specFactor), ambient + (diffFactor + specFactor), ambient + (diffFactor + specFactor), 1.0f);

	//   //float4 finalColor = float4(specFactor, specFactor, specFactor, 1.0f);

	//   return finalColor;

	float3 L = normalize(LPos.xyz - input.PosWorld);
	//skal�r av normalen och dir
	float LN = max(0.0f, dot(input.Normal, L));

	float3 R = reflect(-L, input.Normal);

	//float4 V = normalize(cameraPos - input.PosWorld);
	float3 V = normalize(CPos.xyz - input.PosWorld);

	float  RV = pow(max(0.0f, dot(R, V)), 64.0f);

	float4 i = Ambient + ((Diffuse * LN) + (Specular * RV));

	return i;

	// Debug shading #1: map and return normal as a color, i.e. from [-1,1]->[0,1] per component
	// The 4:th component is opacity and should be = 1
	//return float4(input.Normal*0.5+0.5, 1);
	
	// Debug shading #2: map and return texture coordinates as a color (blue = 0)
//	return float4(input.TexCoord, 0, 1);
}