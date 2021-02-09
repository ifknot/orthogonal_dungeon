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
	class bitmap {

	public:

		using value_type = T;

		bitmap(dim_t size);

		void clear(uint32_t rgba = 0);

	private:

		dim_t size;
		std::vector<T> raw;

	};

	template<typename T>
	inline bitmap<T>::bitmap  (dim_t size) :
		size(size),
		raw(std::vector<T>(static_cast<int>(size.width * size.height)))
	{}

	template<typename T>
	inline void bitmap<T>::clear(uint32_t rgba) {
		uint32_t* p = (uint32_t*)raw.data();
		auto i = raw.size() >> 2;
		while (i--) {
			*(p) = rgba;
			p++;
		}
	}

}
