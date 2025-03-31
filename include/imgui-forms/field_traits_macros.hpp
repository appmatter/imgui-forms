#pragma once

#include <string>
#include <vector>
#include "field_macros_internal.hpp"
#include "field_traits.hpp"
#define FORM_FIELD_GET(model, field, key) \
    if ((key) == #field)                  \
        return model.field;

#define FORM_FIELD_SET(model, field, key, value) \
    if ((key) == #field)                         \
        model.field = value;

#define _FIELD_GETTER(field, type) \
    if (fieldName == #field)       \
        return m.field;

#define _FIELD_SETTER(field, type) \
    if (fieldName == #field)       \
        m.field = value;

#define _FIELD_META(field, type) \
    {#field, type},

#define DEFINE_FORM(model, ...)                                                               \
    namespace imgui_forms                                                                     \
    {                                                                                         \
        template <>                                                                           \
        struct FormFieldTraits<model>                                                         \
        {                                                                                     \
            using FieldMeta = imgui_forms::FieldMeta;                                         \
            static std::string get(const model &m, const std::string &fieldName)              \
            {                                                                                 \
                _FOR_EACH_PAIR(_FIELD_GETTER, __VA_ARGS__)                                    \
                return {};                                                                    \
            }                                                                                 \
            static void set(model &m, const std::string &fieldName, const std::string &value) \
            {                                                                                 \
                _FOR_EACH_PAIR(_FIELD_SETTER, __VA_ARGS__)                                    \
            }                                                                                 \
            static std::vector<FieldMeta> metadata()                                          \
            {                                                                                 \
                return {_FOR_EACH_PAIR(_FIELD_META, __VA_ARGS__)};                            \
            }                                                                                 \
        };                                                                                    \
    }
