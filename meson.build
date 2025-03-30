project('imgui-forms', 'cpp')

imgui_forms_dirs = include_directories('include')

imgui_forms_dep = declare_dependency(
    include_directories: imgui_forms_dirs,
)

meson.override_dependency('imgui-forms', imgui_forms_dep)

if not meson.is_subproject()
    subdir('tests')
endif
