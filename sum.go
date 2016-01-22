
package main

import(
	"fmt"
	"runtime"
	"time"
)

var i = 0

func add(ic chan int){
	for x := 0; x < 1000000; x++ {
		ic <- 1
		i++
		<-ic
	}
}

func sub(ic chan int){
	for x := 0; x < 1000000; x++ {
		ic <- 1
		i--
		<-ic
	}
}

func main(){

	ic := make(chan int, 1)

	GOMAXPROCS(NumCPU())
	go add(ic)
	go sub(ic)

	Sleep(1000*Millisecond)
	Println("The sum is:", i)
}










