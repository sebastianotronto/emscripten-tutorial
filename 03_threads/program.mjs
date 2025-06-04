import Primes from "./build/primes.mjs"

var primes = await Primes();

const count = primes._primes_in_range(1, 100);
console.log("There are " + count + " primes betwees 1 and 100");
