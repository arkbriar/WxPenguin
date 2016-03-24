#ifndef DYNAMICLIB_HPP_LGOHRJON
#define DYNAMICLIB_HPP_LGOHRJON

#include "macros.h"

namespace WxPenguin {
    namespace Plugin {

        using HLIB = void *;

        class DynamicLib {
        public:
            DynamicLib() {}

            ~DynamicLib() {
                if (h_DynamicLib) FreeLib();
                if (_LibName) {
                    delete _LibName;
                    _LibName = nullptr;
                }
            }

            const char* GetName() const {
                return _LibName;
            }

            bool LoadLib(const char* lib_name);

            void* GetSymbolAddress(const char* symbol_name) const;

            void FreeLib();
        private:
            HLIB h_DynamicLib = nullptr;
            char* _LibName = nullptr;
        };

    }
}

#endif /* end of include guard: DYNAMICLIB_HPP_LGOHRJON */
