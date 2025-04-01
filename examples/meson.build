

sys_deps = [
  dependency('glfw3', required: true), # OpenGL
  dependency('gl', required: true), # OpenGL
]

imgui_dep = dependency('imgui', fallback: ['imgui', 'imgui_dep'])
imgui_forms = dependency('imgui-forms', fallback: ['imgui_forms', 'imgui_forms_dep'])

example_form = executable(
  'example_form',
  'src/example_form.cpp',
  dependencies: [imgui_forms, imgui_dep, sys_deps],
  include_directories: include_directories('include'),
)



