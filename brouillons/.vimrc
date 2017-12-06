set number
set rnu
set visualbell
syntax on
set autoindent
set mouse=a
set cc=80
vsplit
nmap <backspace> <left><del>
nmap b :bn<return>
nmap /* :nohl<return>
nmap <tab> <C-w>w
nmap <tab>q <C-w><left>
imap ( ()<left>
imap { {<return><return>}<up><tab>
set smartindent
set wildmenu
set wildmode=list:longest
set wildignore=*.o,*.swp
set hidden
nmap <cr> o<esc>
