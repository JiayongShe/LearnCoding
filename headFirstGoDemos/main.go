package main

import (
	ch07 "headFirstGoDemos/ch07/go/src/github.com/headfirstgo/count"
)

func main() {
	// ch01 chapter demos: 类型等语法基础，变量定义相关
	// ch01.PrintConversions()
	// ch01.PrintFunctions()
	// ch01.Hello()
	// ch01.PrintVariableDeclarations()
	// ch01.PrintTypes()
	// ch01.PrintValues()

	// ch02 chapter demos: 控制流相关
	// ch02.CallingMethods()
	// ch02.GuessGame()
	// ch02.PassFailJudge()

	// ch03 chapter demos: 函数相关
	// ch03.CalcPaintNeeded()

	// ch04 chapter demos: 包相关
	// dansk.Hej()
	// dansk.GodMorgen()
	// deutsch.Hallo()
	// deutsch.GutenTag()
	// greeting.Hello()
	// greeting.Hi()
	// if input, err := keyboard.GetFloat(); err != nil {
	// 	fmt.Println(err)
	// } else {
	// 	fmt.Printf("got float %0.2f", input)
	// }
	// fmt.Println()

	// ch05 chapter demos: 数组相关
	// ch05.CalcAverage()

	// ch06 chapter demos: 切片相关
	// ch06.Average()
	// ch06_2.Average2()

	// ch07 chapter demos: map相关
	ch07.CalcVote()

	// ch08 chapter demos: struct相关
	// ch08.CalcVote()

	// ch13 chapter demos
	// ch13.TestGoroutines()
	// ch13.ChannelGetPageSize()
	// ch13.RunReportNap()

	// ch14 chapter demos: go test相关
	// ch14.Join()

	// ch16 chapter demos: http/template介绍
	// ch16.StartWebAppUsingTemplate()

	// test
	// test.TestSyncWaitGroup()
	// test.TestInputOutput()
	// fmt.Println(test.LongestConsecutive([]int{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}))
	// fmt.Println(test.LengthOfLongestSubstring("bwf"))
}
