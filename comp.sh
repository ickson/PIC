#!/bin/bash
CAMINHO=/opt/microchip/xc8/v1.33/bin/xc8
CHIP=16F628A
$CAMINHO --chip=$CHIP $1.c && mv $1.c temp && mv $1.hex temp2 && rm $1.* && rm startup.* && mv temp2 $1.hex && mv temp $1.c && rm funclist l.*
