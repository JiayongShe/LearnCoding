package ch01

import "fmt"

func PrintVariableDeclarations() {
	var quantity int
	var length, width float64
	var customerName string

	quantity = 4
	length, width = 1.2, 2.4
	customerName = "Damon Cole"

	fmt.Println(customerName)
	fmt.Println("has ordered", quantity, "sheets")
	fmt.Println("each with an area of")
	fmt.Println(length*width, "square meters")

	// short variable declarations
	fmt.Println("---------- short variable declarations ----------")
	quantityShort := 4
	lengthShort, widthShort := 1.2, 2.4
	customerNameShort := "Damon Cole"

	fmt.Println(customerNameShort)
	fmt.Println("has ordered", quantityShort, "sheets")
	fmt.Println("each with an area of")
	fmt.Println(lengthShort*widthShort, "square meters")
	fmt.Println()
}
