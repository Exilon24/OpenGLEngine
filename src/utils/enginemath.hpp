namespace EngineMath {
	float lerp(const float a, const float b, const float t) 
	{
		return a + (b - a) * t;
	}
}
