#pragma once
#include "field_traits.hpp"
#include <string>
#include <unordered_map>
#include <functional>
#include <type_traits>
#include <cpp_forms/form.hpp>

namespace imgui_forms
{

    template <typename T>
    class Bindings
    {
    public:
        explicit Bindings(cpp_forms::Form<T> &form) : form(form) {}

        struct BufferRef
        {
            std::string &buffer;
            std::function<void(const std::string &)> setter;
            std::function<std::string()> getErrors;

            char *data() { return buffer.data(); }
            int capacity() const { return static_cast<int>(buffer.capacity()) + 1; }

            void commit() { setter(buffer); }
            std::string errors() const { return getErrors(); }
        };

        BufferRef operator[](const std::string &field);

        const std::unordered_map<std::string, std::string> &errors() const
        {
            return form.allErrors();
        }

        void commitAll();
        void clear();

    private:
        cpp_forms::Form<T> &form;

        std::unordered_map<std::string, std::string> &bufferMap();

        std::string getFieldValue(const std::string &field);
        void setFieldValue(const std::string &field, const std::string &val);
    };

}

#include "bindings_impl.inl"
