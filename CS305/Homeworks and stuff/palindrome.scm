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
        #f
      )
    ) 
  )
)


(define same-sequence?
  (lambda (inSeq1 inSeq2)
    (if (and (null? inSeq1) (null? inSeq2))
      #t
      (if (or (null? inSeq1) (null? inSeq2))
        #f
        (if (sequence? inSeq1)
          (if (sequence? inSeq2) 
            (if (eq? (car inSeq1) (car inSeq2))
              (same-sequence? (cdr inSeq1) (cdr inSeq2))
              #f
            )
            #f
          )
          #f
        ) 
      )
    )
  )
)


(define reverse-sequence
  (lambda (inSeq)
    (if (sequence? inSeq)
      (if (null? inSeq)
        '()
          (append (reverse-sequence (cdr inSeq))
          (list (car inSeq)))
      )
    #f
    )
  )
)

(define member?
  (lambda (inSym inSeq)
    (if (and (symbol? inSym) (sequence? inSeq))
      (if (null? inSeq)
        #f
        (if (eq? (inSym) (car inSeq))
          #t
          (member? inSym (cdr inSeq))
        )
      )
      #f
    )
  )
)

(member? 'b '(a b c))









 


 

