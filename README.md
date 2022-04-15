# opencv_ahk

The project is opencv ahk binding, use [autoit-opencv](https://github.com/smbape/node-autoit-opencv-com) project to generate opencv header file data, and then rebind it to ahk_v2.
This library dependents on opencv_world4.5.5 x64 and [ahk_v2h.beta.3-fixed.5(exe or dll)](https://github.com/thqby/AutoHotkey_H/releases/tag/v2.0-beta.3-fixed.5)
The parameter type definition is the same as that of C++ version, and some functions are not completely overloaded.
[opencv documentation](https://docs.opencv.org/4.x/)

## examples
To use in v2L, you need to load the ahk.dll.

```
#DllLoad opencv_ahk.dll
#DllLoad AutoHotkey64.dll
api := DllCall('autohotkey64.dll\ahkGetApi', 'cdecl ptr')
; api := DllCall(A_AhkPath '\ahkGetApi', 'cdecl ptr')  ; ahk_h.exe
cv := ObjFromPtr(DllCall('opencv_ahk.dll\opencv_init', 'ptr', api, 'cdecl ptr'))
mat := cv.Mat(300, 300, cv.constants.CV_8UC3, [120,100,200])
loop 40 {
	row := A_Index
	loop 40
		mat[row, A_Index] := [Random(0, 255),Random(0, 255),Random(0, 255),]
}

cv.putText(mat, "ahk", [50, 50], cv.constants.FONT_HERSHEY_COMPLEX, 2, [0, 0, 255], 1, 8, false)
cv.imshow('src', mat)
MsgBox
```

## parameter type conversion
- `InputArray, OutputArray, InputOutputArray`, these parameters can use `Mat` or `UMat` or `cuda_GpuMat` or `Vector` objects.
- `vector<xx>`, use `Vector_xx`(if the class exists) or `Array` objects.
- the classes and structs of opencv, use class instances of the corresponding type(if the class exists), or `Array`(if the class does not exist).
- When overloaded functions have integer, float and string type parameters at the same time, the corresponding types shall be strictly used.
- Parameters of the `CV_OUT` macro tag that the type is not `(Input)OutputArray`, use `VarRef`.
