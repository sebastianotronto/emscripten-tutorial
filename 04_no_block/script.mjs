var aInput = document.getElementById("aInput");
var bInput = document.getElementById("bInput");
var button = document.getElementById("goButton");
var resultText = document.getElementById("resultText");

var worker = new Worker("./worker.mjs", { type: "module" });

button.addEventListener("click", () => worker.postMessage({
	a: Number(aInput.value),
	b: Number(bInput.value)
}));

worker.onmessage = (e) => resultText.innerText = "There are " +
	e.data.result + " primes between " + e.data.a + " and " + e.data.b;
