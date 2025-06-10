import Primes from "./build/primes.mjs"

var primes = await Primes();

var low = 1;
var high = 10000000;
const count = primes._primes_in_range(low, high);
console.log("There are " + count + " primes between " + low + " and " + high);
