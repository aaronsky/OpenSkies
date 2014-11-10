#version 330 core

struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

struct DirectionLight {
	vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct PointLight {
	vec3 position;
	
	float constant;
	float linear;
	float quadratic;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec3 Position;
in vec3 Normal;
in vec2 TexCoords;

out vec4 color;

uniform vec3 viewPos;
uniform DirectionLight dirLights[1];
uniform PointLight pointLights[4];
uniform Material material;

vec3 CalculateDirectionLight(DirectionLight light, Material mat, vec3 normal, vec3 viewDirection);
vec3 CalculatePointLight(PointLight light, Material mat, vec3 normal, vec3 fragPosition, vec3 viewDirection);

void main()
{
	vec3 norm = normalize(Normal);
	vec3 viewDir = normalize(viewPos - Position);

	vec3 result;
	for (int i = 0; i < 1; i++)
	{
		result += CalculateDirectionLight(dirLights[i], material, norm, viewDir);	
	}
	for (int i = 0; i < 4; i++)
	{
		result += CalculatePointLight(pointLights[i], material, norm, Position, viewDir);
	}

	color = vec4(result, 1.0);
}

vec3 CalculateDirectionLight(DirectionLight light, Material mat, vec3 normal, vec3 viewDirection)
{
	vec3 lightDir = normalize(-light.direction);
	float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDirection, reflectDir), 0.0), mat.shininess);
    vec3 ambient = light.ambient * vec3(texture(mat.diffuse, TexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(mat.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(mat.specular, TexCoords));
    return (ambient + diffuse + specular);
}

vec3 CalculatePointLight(PointLight light, Material mat, vec3 normal, vec3 fragPosition, vec3 viewDirection)
{
	vec3 lightDir = normalize(light.position - fragPosition);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDirection, reflectDir), 0.0), mat.shininess);
    float distance = length(light.position - fragPosition);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    vec3 ambient = light.ambient * vec3(texture(mat.diffuse, TexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(mat.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(mat.specular, TexCoords));
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}