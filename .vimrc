let g:syntastic_c_include_dirs = [ 'includes', 'lib/libft/includes', 'lib/GLFW/include' ]
let g:clang_user_options = '-Wall -Werror -DCLANG_COMPLETE'

autocmd BufNewFile,BufRead *.glslv set syntax=c
autocmd BufNewFile,BufRead *.glslf set syntax=c
