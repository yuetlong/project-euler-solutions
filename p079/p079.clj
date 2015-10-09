(defn p079
  "Returns the precedence of numbers in pairs. Need to use pen and paper to evaluate the answer."
  []
  (->> (slurp "p079_keylog.txt")
       (#(clojure.string/split % #"\n"))
       (mapcat #(partition 2 1 %))
       (distinct)
       (sort-by first)))
