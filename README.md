# picmip-plugin
Metamod plugin for increasing the range of mat_picmip in TF2 from [-1, 2] to [-10, 10].

Based on [https://github.com/momentum-mod/game/issues/495](https://github.com/momentum-mod/game/issues/495)  
Shoutout to [Aris Poloway](https://github.com/arispoloway/) for help with Metamod

# Installation
- [Install Metamod](https://wiki.alliedmods.net/Installing_Metamod:Source)
- Grab `picmip.dll` from the Releases tab or compile it yourself and place it in `/tf/addons`

# Usage
- Launch TF2 with `-insecure` flag
- `meta load addons/picmip`
- `picmip set <value>`  
**Note:** Due to the way mat_picmip is handled in the engine, this command only works once.  
If you want to use it again, you will need to restart your game.

# Screenshots
`picmip set 10`:  
![mat_picmip 10](/screenshots/mat_picmip_10.png)  

`picmip set -10` (looks pretty much like -1 to me):  
![mat_picmip -10](/screenshots/mat_picmip_-10.png)
