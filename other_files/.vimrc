"Active la numérotation des lignes
:set nu

"Numérotation à partir du curseur
:set rnu

"Split verticalement
:vsplit 

"Colorisation
:syntax on

"Indentation auto quand <return> (à partir du precédant niveau)
:set autoindent

"Keymap => 
:nmap <backspace> <left><del>
:nmap b :bn<return>
:nmap µ :nohl<return>
:nmap <tab> <C-w>w
:nmap <tab>q <C-w><left>
:imap ( ()<left>
:imap { {}<left><return><return><up><tab>
