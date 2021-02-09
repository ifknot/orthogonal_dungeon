/*****************************************************************//**
 * \file   bitmap.h
 * \brief  raw image data structure
 * 
 * \author ifkno
 * \date   February 2021
 * \version 2.0
 *********************************************************************/
#pragma once

#include "types.h"

namespace box {

	template<typename T = char>
	class bitmap_t {

	public:

		using value_type = T;

		bitmap_t(dim_t size);

		void clear(uint32_t rgba = 0) {
			uint32_t* p = (uint32_t*)raw.data();
			auto i = raw.size() >> 2;
			while(i--) {
				*(p) = rgba;
				p++;
			}
		}

	private:

		dim_t size;
		std::vector<T> raw;

	};

	template<typename T>
	inline bitmap_t<T>::bitmap_t(dim_t size) :
		size(size),
		raw(std::vector<T>(static_cast<int>(size.width * size.height)))
	{}

}
