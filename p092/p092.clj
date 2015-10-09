(defn exp [n x]
  (reduce * (repeat x n)))

(defn add-square-of-digits [num]
  (loop [n num a 0]
    (if (zero? n)
      a
      (recur (quot n 10) (+ a (exp (mod n 10) 2))))))

(defn p092 []
  (letfn [(number-chain [num] (iterate add-square-of-digits num))
          (first-of-loop [num] (first (second (split-with #(and (not= 1 %) (not= 89 %)) (number-chain num)))))]
    (count (filter #(= % 89) (map first-of-loop (range 2 1e7))))))
