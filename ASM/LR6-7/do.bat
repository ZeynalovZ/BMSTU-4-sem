cls
del log


masm lr6.asm,,,; >>log
masm lr6_bs.asm,,,; >>log
masm lr6_bu.asm,,,; >>log
masm lr6_ds.asm,,,; >>log
masm lr6_du.asm,,,; >>log
masm lr6_hs.asm,,,; >>log
masm lr6_hu.asm,,,; >>log
masm lr6_in.asm,,,; >>log



echo "link" >>log
link  lr6.obj lr6_bs.obj lr6_bu.obj lr6_ds.obj lr6_du.obj lr6_hs.obj lr6_hu.obj lr6_in.obj,,; >>log
cls
