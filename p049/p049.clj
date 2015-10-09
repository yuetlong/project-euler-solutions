(load-file "sieve.clj")

(defn split-num [num]
  (map (fn [x] (Integer/valueOf (apply str x))) (partition 1 (str num))))

(def four-digit-primes
  (drop-while #(< % 1000) (take-while #(< % 10000) (lazy-primes))))

(defn sorted-val [num]
  (int (reduce + (map-indexed #(* (Math/pow 10 %1) %2) (reverse (sort (split-num num)))))))

(defn plus-3330-6660 [coll]
  (loop [c coll]
    (let [f (first c)]
      (cond (= 2 (count c)) nil
            (and (some (partial = (+ 3330 f)) c)
                 (some (partial = (+ 6660 f)) c)) f
                 :else (recur (rest c))))))

(defn evaluate-answer [num]
  (+ (* num 100000000) (* (+ 3330 num) 10000) (+ 6660 num)))

(defn p049 []
  (->> four-digit-primes
       (group-by sorted-val)
       (vals)
       (filter #(< 3 (count %)))
       (map plus-3330-6660)
       (remove nil?)
       (remove (partial = 1487))
       (first)
       (evaluate-answer)))
