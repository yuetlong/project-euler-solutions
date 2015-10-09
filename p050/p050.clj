(load-file "sieve.clj")

(defn p050
  "Evaluates the prime number that can be written as the sum of most consecutive primes under the value of target."
  []
  (let [target 1000000
                                        ; search target
        reversed-primes (reverse (take-while #(< % target) (lazy-primes)))
                                        ;a descending realized sequence of primes below target.
        amount (count (take-while #(< % target) (reductions + (lazy-primes))))
                                        ; the amount of primes that is less than target when summed together.
        primes (take amount (lazy-primes))]
                                        ; a sequence of primes in that amount
    (letfn [(prime? [num] (= num (first (drop-while #(> % num) reversed-primes))))]
                                        ; a prime checker that implemented linear search on sorted prime sequence.
      (first (filter prime? (map #(reduce + %) (mapcat #(partition % 1 primes) (range amount 1 -1)))))
                                        ; Mapcat generates all possibilities where primes are grouped together.
                                        ; These possibilities are generated in descending order of the number of elements.
                                        ; For instance, in target = 100 case, mapcat generates:
                                        ; ((2 3 5 7 11 13) (2 3 5 7 11) (3 5 7 11 13) (2 3 5 7) (3 5 7 11) ...)
                                        ; Then we add up everything within the subsequences
                                        ; At last we find the first prime in the list, which is summed up by the biggest amount of primes.
      )))
