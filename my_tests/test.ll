@format_str = private constant [15 x i8] c"Hello, World!\0A\00"

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
    %my_str = [15 x i8] c"Hello, World!\0A\00"
    %0 = call i32 (i8*, ...) @printf(i8* getelementptr ([13 x i8], [13 x i8]* @format_str, i32 0, i32 0))
    ret i32 0
}
