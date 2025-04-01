#pragma once
#include "bindings.hpp"

namespace imgui_forms
{

    template <typename T>
    typename Bindings<T>::BufferRef Bindings<T>::operator[](const std::string &field)
    {
        auto &buf = bufferMap()[field];

        if (buf.empty())
        {
            buf = getFieldValue(field);
            auto it = bufferCapacities.find(field);
            if (it != bufferCapacities.end())
            {
                buf.reserve(it->second);
            }
            else
            {
                buf.reserve(128); // default
            }
        }

        return BufferRef{
            buf,
            [this, field](const std::string &val)
            {
                setFieldValue(field, val);
            },
            [this, field]() -> std::string
            {
                return form.hasError(field) ? form.error(field) : "";
            }};
    }

    template <typename T>
    std::unordered_map<std::string, std::string> &Bindings<T>::bufferMap()
    {
        static thread_local std::unordered_map<std::string, std::string> map;
        return map;
    }

    template <typename T>
    void Bindings<T>::commitAll()
    {
        for (auto &[field, buf] : bufferMap())
        {
            setFieldValue(field, buf);
        }
    }

    template <typename T>
    void Bindings<T>::clear()
    {
        bufferMap().clear();
    }

    template <typename T>
    std::string Bindings<T>::getFieldValue(const std::string &field)
    {
        return imgui_forms::FormFieldTraits<T>::get(form.data(), field);
    }

    template <typename T>
    void Bindings<T>::setFieldValue(const std::string &field, const std::string &val)
    {
        imgui_forms::FormFieldTraits<T>::set(form.data(), field, val);
    }

    template <typename T>
    void Bindings<T>::setBufferCapacity(const std::string &field, size_t capacity)
    {
        bufferCapacities[field] = capacity;
    }
}