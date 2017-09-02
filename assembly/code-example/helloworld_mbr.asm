          ;代码清单1-1
          ;文件名: mbr.asm
          ;文件说明：硬盘主引导扇区代码
          ;创建日期：2017-09-03 03:00
          
          mov ax,0xb800       ;指向文本模式的显示缓冲区
          mov es, ax
          
          ;在80*25的显示器第一行中间显示hello  world
          mov byte [es:68],'h'
          mov byte [es:69],0x07
          mov byte [es:70],'e'
          mov byte [es:71],0x07
          mov byte [es:72],'l' 
          mov byte [es:73],0x07
          mov byte [es:74],'l'
          mov byte [es:75],0x07
          mov byte [es:76],'o'
          mov byte [es:77],0x07
          
          mov byte [es:82],'w'
          mov byte [es:83],0x07
          mov byte [es:84],'o'
          mov byte [es:85],0x07
          mov byte [es:86],'r'
          mov byte [es:87],0x07
          mov byte [es:88],'l'
          mov byte [es:89],0x07
          mov byte [es:90],'d'
          mov byte [es:91],0x07
          
   infi:  jmp near infi
   times 382 db 0
   dw 0xaa55
    
           