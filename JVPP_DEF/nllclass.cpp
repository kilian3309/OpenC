#include "nllclass.h"
#include "types.h"

null_class::operator Core::Type() const {
	return Core::Type(L"");
}