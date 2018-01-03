# VLCStation
A user script to make play buttons in Synology Video Station generate VLC playlists rather than playing videos in the browser.

Installation
------------

Download and add the VLC Station user script using your preferred user script manager.

Video Station will offer videos you play as "playlist.vlc".

You can then set up your browser to automatically open playlists for seamless VLC playback.

In Firefox (and variants):
 - In options, ensure that the "application/videolan" content type is handled by VLC
   Alternatively, when prompted to save a playlist, choose to open it with VLC and tell Firefox to always open files of that type

In Iron (and presumably Chrome):
 - After downloading your first playlist, click on the arrow menu to the right of the file and tick "Always open files of this type"
 - You will need to ensure the Windows file association for .vlc files is handled by VLC

---

For Windows users, VLC Station also comes with a small, optional utility to improve the playback experience.

To download it, choose "Download VLC Full Screen Launcher (Windows)" from the Greasemonkey User Script Commands menu.

You can also get it directly here: https://github.com/gurok/VLCStation/releases/download/v1/vlc-full.exe

The source is available here: https://github.com/gurok/VLCStation/tree/master/vlc-full

This utility launches VLC with the following parameters:
 - -F (Full screen)
 - --play-and-stop (Exit after playing the last item in the playlist)
 - --playlist-autostart (Start playback automatically)
 - --no-random (Play items in order (surprisingly, not the default in newer versions of VLC))
 - --no-loop (Do not loop through items in the playlist)

To use it, place the utility in the same directory as "vlc.exe" and point your file association to "vlc-full.exe" instead.

Notes
-----

Tested with:
 - Firefox (Windows) (Greasemonkey 4)
 - Pale Moon (Windows) (Greasemonkey 3.3 RC4)
 - Iron (Windows) (Tampermonkey)

Support for the "TV Recording" video type is untested. I was unable to get my DiskStation to work with my DTV adapter.

Support for Linux and other operating systems, and indeed anything not explicitly tested above is not guaranteed.

Feedback about operating system and browser compatibility is welcome.
