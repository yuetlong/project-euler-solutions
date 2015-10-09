(defn p059 []
  (->> (slurp "p059_cipher.txt")
       (drop-last 2)
       (reduce str)
       #(clojure.string/split % #",")))
