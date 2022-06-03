float4x4 gWorldMatrix : World;
float4x4 gViewMatrix : View;
float4x4 gProjectionMatrix : Projection;

float4 gColor;


struct VS_INPUT
{
	float4 mPosition : POSITION;
};

struct VS_OUTPUT
{
	float4 mPosition : POSITION;
};


VS_OUTPUT ColorShader_Pass_0_Vertex_Shader_vs_main(VS_INPUT Input)
{
	VS_OUTPUT Output;

	Output.mPosition = mul(Input.mPosition, gWorldMatrix);
	Output.mPosition = mul(Output.mPosition, gViewMatrix);
	Output.mPosition = mul(Output.mPosition, gProjectionMatrix);

	return Output;
}

float4 ColorShader_Pass_0_Pixel_Shader_ps_main() : COLOR
{
	return gColor;
}

technique ColorShader
{
	pass Pass_0
	{
		VertexShader = compile vs_2_0 ColorShader_Pass_0_Vertex_Shader_vs_main();
		PixelShader = compile ps_2_0 ColorShader_Pass_0_Pixel_Shader_ps_main();
	}
}
