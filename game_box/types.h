/*****************************************************************//**
 * \file   types.h
 * \brief  game box 2d graphics types
 * 
 * \author ifkno
 * \date   February 2021
 *********************************************************************/
#pragma once

#include <cstdint>
#include <vector>

namespace box {

	using fp_t = double;

	typedef union word_t {
		uint16_t word{ 0 };
		struct {
			uint8_t lo;
			uint8_t hi;
		} byte;
	} word_t;

	/**
	 * sRGB (IEC 61966-2-1:1999) colour space with alpha transparency channel.
	 * defaults to opaque black
	 */
	struct rgba_t {

		fp_t r{ 0.0 }, g{ 0.0 }, b{ 0.0 }, a{ 1.0 };

		uint32_t raw() {
			uint32_t R{ static_cast<uint32_t>(255.0 * r) };
			uint32_t G{ static_cast<uint32_t>(255.0 * g) << 8 };
			uint32_t B{ static_cast<uint32_t>(255.0 * b) << 16 };
			uint32_t A{ static_cast<uint32_t>(255.0 * a) << 24 };
			return R | G | B | A;
		}

	};

	/**
	 * hue, saturation, value(brightness) colour space.
	 */
	struct hsv_t {

		fp_t h{ 0.0 }, s{ 0.0 }, v{ 0.0 };

	};

	struct point_t {

		int x{ 0 };
		int y{ 0 };

	};

	struct dim_t {

		int width{ 0 };
		int height{ 0 };

	};

	struct rect_t {

		point_t point;
		dim_t	size;

	};

}