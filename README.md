# opencv_ahk

The project is opencv-ahk bindings, use [autoit-opencv](https://github.com/smbape/node-autoit-opencv-com) project to generate opencv header file data, and then rebind it to ahk_v2.
This library dependents on opencv_world4.5.5 x64 and [ahk_v2h.beta.3-fixed.5(exe or dll)](https://github.com/thqby/AutoHotkey_H/releases/tag/v2.0-beta.3-fixed.5)
The parameter type definition is the same as that of C++ version, and some functions are not completely overloaded.
[opencv documentation](https://docs.opencv.org/4.x/)

## examples
To use in v2L, you need to load the ahk.dll.

```
#DllLoad opencv_ahk.dll
#DllLoad AutoHotkey64.dll

; cv := ObjFromPtr(DllCall('opencv_ahk.dll\opencv_init', 'ptr', DllCall(A_AhkPath '\ahkGetApi', 'cdecl ptr'), 'cdecl ptr'))	; ahk_h
cv := ObjFromPtr(DllCall('opencv_ahk.dll\opencv_init', 'ptr', DllCall('autohotkey64.dll\ahkGetApi', 'cdecl ptr'), 'cdecl ptr'))

cvcons := cv.constants
img := cv.imread(A_ScriptDir '\1.png')
cv.imshow('img', img)
cv.waitKey()
cv.cvtColor(img, img_grey := cv.mat(), cvcons.COLOR_BGR2GRAY)
cv.imshow('img', img_grey)
cv.waitKey()
ret := cv.threshold(img_grey, thresh := cv.mat(), 200, 255, cvcons.THRESH_BINARY)
cv.imshow('img', thresh)
cv.waitKey()
cv.findContours(thresh, contours := cv.Vector_Vector_Point(), hierarchy := cv.vector_vec4i(), cvcons.RETR_TREE, cvcons.CHAIN_APPROX_SIMPLE)
cv.drawContours(img, contours, -1, [0, 0, 255, 0], 2)
cv.imshow("img", img)
cv.waitKey()
cv.putText(img, "hello ahk⛅", [0,50], cv.constants.FONT_HERSHEY_SIMPLEX, 1, [0, 0, 255], 2, 8, 0)
cv.putText(img, "hello ahk⛅", [0,50], cv.constants.FONT_HERSHEY_SIMPLEX, 1, [0, 0, 255], 2, 8, 1)
td := cv.TextDraw(,48)
td.putText(img, 'hello ahk⛅', [0,150], [255], 1)
td.putText(img, 'hello ahk⛅', [0,150], [255], 0)
loop 40 {
	row := A_Index
	loop 40
		img[row + 270, A_Index + 20] := [Random(0, 255),Random(0, 255),Random(0, 255),]
}
cv.imshow('img', img)
cv.waitKey()
cv.destroyAllWindows()
```

## parameter type conversion
- `InputArray, OutputArray, InputOutputArray`, these parameters can use `Mat` or `UMat` or `cuda_GpuMat` or `Vector` objects.
- `vector<xx>`, use `Vector_xx`(if the class exists) or `Array` objects.
- the classes and structs of opencv, use class instances of the corresponding type(if the class exists), or `Array`(if the class does not exist).
- When overloaded functions have integer, float and string type parameters at the same time, the corresponding types shall be strictly used.
- Parameters of the `CV_OUT` macro tag that the type is not `(Input)OutputArray`, use `VarRef`, and the initial value needs to be provided when there is a `CV_IN` macro tag.
