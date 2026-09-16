# Specification

ynote reads text files is a bit like lilypond and play notes.

An ynote file consists of commands and notes.
A command begin with a ! and finish with a newline.

Commands:

- `tempo <bpm>`: Set bpm for quarter note (default 120)
- `transpose <int>`: Transpose (specified in semitones)
- `trasnpose_whole <float>`: Transpose (specified in whole tones)

Notes:

ynote play cis the same as des.

```
c/bis/deses
cis/des
d/cisis/eses/eeses
dis/es/ees
e/disis/fes
f/eis/geses
fis/ges
g/fisis/ases/asas/aeses
gis/as/aes
a/gisis/beses : 440
ais/bes
b/aisis/ces

r/x : rest
```

The notes are accompanied with a duration specifier.
If you omit it, it will be 4 or the same as the previous note.

Duration specificator are `1`, `2`, `4`, `8`, `16` and `32`.
You can append `.` to add half of the specifier.

Example:

```
!tempo 100

e4 fis4 gis4 a4 gis4 fis4 e2
fis gis a b a gis fis2
e r e r e r e r
e8 e8 fis8 fis8 gis8 gis8 a8 a8 gis4 fis4 e2
```
