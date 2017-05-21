#pragma once
#include "file.h"
#include "fwd.h"
#include <vector>

namespace Core {
	class compiler {
		std::vector<File*> m_Files;

	public:
		inline compiler() {

		}


		inline void addFile(File* f) {
			m_Files.push_back(f);
		}

	};

}