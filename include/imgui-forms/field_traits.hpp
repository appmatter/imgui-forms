#pragma once

#include <string>
#include <stdexcept>

namespace imgui_forms
{

    struct FieldMeta
    {
        std::string name;
        std::string type;
    };

    // This must be specialized by the user for their model types
    template <typename T>
    struct FormFieldTraits;

}