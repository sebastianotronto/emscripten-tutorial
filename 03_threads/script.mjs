import Primes from "./build/primes.mjs";

var primes = await Primes();

var aInput = document.getElementById("aInput");
var bInput = document.getElementById("bInput");
var button = document.getElementById("goButton");
var resultText = document.getElementById("resultText");

button.addEventListener("click", () => {
	var a = Number(aInput.value);
	var b = Number(bInput.value);
	const count = primes._primes_in_range(a, b);
	resultText.innerText = "There are " + count + " primes between " +
	    a + " and " + b;
});
