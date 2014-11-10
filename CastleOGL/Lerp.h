#ifndef _LERP_H_
#define _LERP_H_

inline float lerp(const float min, const float max, const float t)
{
	return min + t * (max - min);
}
#endif