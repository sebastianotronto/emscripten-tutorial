import Primes from "./build/primes.mjs";

var primes = await Primes();
const logPtr = primes.addFunction((cstr) => {
	postMessage({ message: primes.UTF8ToString(cstr) });
}, "vp");

onmessage = (e) => {
	const count = primes._primes_in_range(e.data.a, e.data.b, logPtr);
	postMessage({ message: "There are " + count + " primes between " +
		e.data.a + " and " + e.data.b });
};
