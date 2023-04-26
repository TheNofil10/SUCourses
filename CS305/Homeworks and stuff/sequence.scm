(define symbol-length
(lambda (inSym)
(if (symbol? inSym)
(string-length (symbol->string inSym))
0
)
)
)


(define sequence?
  (lambda (inSeq)
    (if (null? inSeq)
      #t
      (if (list? inSeq)
        (if (symbol? (car inSeq))
          (if (eq? 1 (symbol-length (car inSeq)))
            (sequence? (cdr inSeq))
            #f
          )
          #f
        )
      )
    ) 
  )
)
(sequence? '(a (b c)))

