" Set map leader
let mapleader = ","

" 去掉行尾空格
autocmd BufWritePre * :%s/\s\+$//e

"Use vundle to manage plugin, required turn file type off and nocompatible

"------------------------------------------->
"" Bundle begin
" ------------------------------------------>
filetype off                   " required!
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'gmarik/Vundle.vim'

" add other plugin here
Plugin 'conormcd/matchindent.vim'

"ctages
Plugin 'ludovicchabant/vim-gutentags'

"git Plugin: vim-fugitive
Plugin 'tpope/vim-fugitive'

" YCM for completions
Plugin 'Valloric/YouCompleteMe'
let g:ycm_confirm_extra_conf = 0
let g:ycm_filepath_completion_use_working_dir = 1
let g:ycm_key_list_select_completion = []
let g:ycm_key_list_previous_completion = []
let g:ycm_collect_identifiers_from_tags_files = 1
let g:ycm_filetype_whitelist = {'c': 1, 'cpp': 1, 'python': 1}
let g:ycm_collect_identifiers_from_tags_files = 1
nnoremap <F4> :YcmDiags<CR>
nnoremap <F5> :YcmForceCompileAndDiagnostics<CR>
nnoremap <Leader>] :YcmCompleter GoTo<CR>
nnoremap <Leader>gh :YcmCompleter GoToInclude<CR>
nnoremap <Leader>gd :YcmCompleter GoToDefinition<CR>
nnoremap <Leader>gc :YcmCompleter GoToDeclaration<CR>

Plugin 'SirVer/ultisnips'
Plugin 'honza/vim-snippets'
let g:UltiSnipsSnippetDirectories=["UltiSnips", 'mysnips']
let g:snips_author = 'Jiayong.She (She)'
let g:snips_email = 'shejiayong@skybility.com'
let g:snips_github = ''
let g:snips_company = 'Skybility Software Co.,Ltd.'

Plugin 'klen/python-mode'


call vundle#end()            " required
" Enable file type plugin and indent
filetype plugin indent on
"-------------------------------------------
" Bundle end
" ------------------------------------------


set nocompatible  " Use Vim defaults instead of 100% vi compatibility
syntax enable
syntax on

"Show line number, command, status line and so on
set history=1000
set ruler
set number
set showcmd
set showmode
set laststatus=2
set cmdheight=2
set scrolloff=3

"Fill space between windows
set fillchars=stl:\ ,stlnc:\ ,vert:\


"Turn off splash screen
set shortmess=atI

colorscheme desert
set background=dark
set cursorline
set cursorcolumn

"Configure backspace to be able to across two lines
set backspace=2
set whichwrap+=<,>,h,l

" 自动缩进
set tabstop=4 " tab width
set shiftwidth=4 " width of nested tabs
set expandtab " input spaces instead of tab when typing a tab
set softtabstop=4 " 1. space deleted when typing <BackSpace>
set smarttab
set autoindent
set cindent



set guifont=Courier_New:h10:cANSI   " 设置字体
"set cmdheight=1     " 命令行（在状态行下）的高度，设置为1
"set scrolloff=3     " 光标移动到buffer的顶部和底部时保持3行距离
set novisualbell    " 不要闪烁(不明白)
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}   "状态行显示的内容
set laststatus=1    " 启动显示状态行(1),总是显示状态行(2)
"set background=dark "背景使用黑色
set nocompatible  "去掉讨厌的有关vi一致性模式，避免以前版本的一些bug和局限
" 设置配色方案
"字体
"if (has("gui_running"))
"   set guifont=Bitstream\ Vera\ Sans\ Mono\ 10
"endif


set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8
set fileencodings=ucs-bom,utf-8,cp936,gb18030,gbk " open file with"
set fileencoding=utf-8
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

""实用设置
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"自动保存
set autowrite
""set ruler                   " 打开状态栏标尺
""set cursorline              " 突出显示当前行

"set statusline=\ %<%F[%1*%M%*%n%R%H]%=\ %y\ %0(%{&fileformat}\ %{&encoding}\ %c:%l/%L%)\
" 设置在状态行显示的信息
"set foldcolumn=0
"set foldmethod=indent
"set foldlevel=3
" 不要使用vi的键盘模式，而是vim自己的
set nocompatible
" 在处理未保存或只读文件的时候，弹出确认
set confirm
" 显示行号
""set number
" 历史记录数
""set history=1000
"搜索逐字符高亮
set hlsearch
set incsearch
"编码设置
set enc=utf-8
set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
"语言设置
set langmenu=zh_CN.UTF-8
set helplang=cn
" 我的状态行显示的内容（包括文件类型和解码）
"set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}
"set statusline=[%F]%y%r%m%*%=[Line:%l/%L,Column:%c][%p%%]
" 总是显示状态行
set laststatus=2
" 命令行（在状态行下）的高度，默认为1，这里是2
""set cmdheight=2
" 侦测文件类型
""filetype on
" 载入文件类型插件
""filetype plugin on
" 保存全局变量
set viminfo+=!
" 可以在buffer的任何地方使用鼠标（类似office中在工作区双击鼠标定位）
"set mouse=v
set selection=exclusive
"set selectmode=mouse,key
" 通过使用: commands命令，告诉我们文件的哪一行被改变过
set report=0
" 在被分割的窗口间显示空白，便于阅读
set fillchars=vert:\ ,stl:\ ,stlnc:\
" 高亮显示匹配的括号
set showmatch
" 匹配括号高亮的时间（单位是十分之一秒）
set matchtime=1

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"括号补全
inoremap ( ()<ESC>i

inoremap [ []<ESC>i

inoremap { {}<ESC>i

inoremap < <><ESC>i

inoremap ' ''<ESC>i

inoremap " ""<ESC>i


let &colorcolumn="80"

nmap    w=  :resize +3<CR>
nmap    w-  :resize -3<CR>
nmap    w,  :vertical resize -3<CR>
nmap    w.  :vertical resize +3<CR>
