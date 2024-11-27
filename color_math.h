typedef struct
{
    float3 c0, c1, c2;
}
mat3;

__DEVICE__ inline mat3 make_mat3(const float3 A, const float3 B, const float3 C)
{
    mat3 D;
    D.c0 = A; D.c1 = B; D.c2 = C;
    return D;
}

__DEVICE__ inline float3 mult_f3_f33(const float3 X, const mat3 A)
{
    float r[3];
    float x[3] = {X.x, X.y, X.z};
    float a[3][3] =	{{A.c0.x, A.c0.y, A.c0.z}, {A.c1.x, A.c1.y, A.c1.z}, {A.c2.x, A.c2.y, A.c2.z}};

    for(int i = 0; i < 3; ++i)
    {
        r[i] = 0.0f;
        for(int j = 0; j < 3; ++j)
        {
            r[i] = r[i] + x[j] * a[j][i];
        }
    }

    return make_float3(r[0], r[1], r[2]);
}

__DEVICE__ inline mat3 invert_f33(const mat3 m)
{
    mat3 mi = make_mat3(make_float3(1.f, 0.f, 0.f), make_float3(0.f, 1.f, 0.f), make_float3(0.f, 0.f, 1.f));

	float det = m.c0.x * (m.c1.y * m.c2.z - m.c2.y * m.c1.z) + m.c1.x * (m.c2.y * m.c0.z - m.c0.y * m.c2.z) + m.c2.x * (m.c0.y * m.c1.z - m.c1.y * m.c0.z);

	if (det == 0.0) return mi;

    det = 1.f / det;

	mi.c0.x = (m.c1.y * m.c2.z - m.c2.y * m.c1.z) * det;
	mi.c0.y = (m.c2.y * m.c0.z - m.c0.y * m.c2.z) * det;
	mi.c0.z = (m.c0.y * m.c1.z - m.c1.y * m.c0.z) * det;

	mi.c1.x = (m.c1.z * m.c2.x - m.c2.z * m.c1.x) * det;
	mi.c1.y = (m.c2.z * m.c0.x - m.c0.z * m.c2.x) * det;
	mi.c1.z = (m.c0.z * m.c1.x - m.c1.z * m.c0.x) * det;

	mi.c2.x = (m.c1.x * m.c2.y - m.c2.x * m.c1.y) * det;
	mi.c2.y = (m.c2.x * m.c0.y - m.c0.x * m.c2.y) * det;
	mi.c2.z = (m.c0.x * m.c1.y - m.c1.x * m.c0.y) * det;

	return mi;
}
