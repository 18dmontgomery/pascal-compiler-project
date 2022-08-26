#include "header.h"

void reservedList()
{

    char buffer2[72];
    FILE *reserved = fopen("reserved.txt", "r");

    token *res = malloc(sizeof(token));
    tokenList = res;

    while (fgets(buffer2, 72, reserved))
    {
        sscanf(buffer2, "%s %s %d %s %d", res->lex, res->tokenname, &res->type, res->attname, &res->types.att);
        res->next = malloc(sizeof(token));
        res = res->next;
    }

    res = tokenList;
}

void updateGreenNode()
{

    while (nodeList->colorNode != GREENNODE)
    {
        nodeList = nodeList->prev;
    }
}

void getGreenBack()
{
    while (nodeList->next != NULL)
    {
        nodeList = nodeList->next;
    }
}

void createGreenNode(char lexName[20], int type)
{
    nodeList = eye;
    token *newNode = (token *)malloc(sizeof(token));
    token *prevNode = malloc(sizeof(token));
    token *last = malloc(sizeof(token));
    token *tempGreenNode;
    token *tempNewNode;
    int asdf = 0;

    int t = type;

    if (nodeList == NULL)
    {

        strcpy(newNode->lex, lexName);
        newNode->type = type;

        newNode->colorNode = GREENNODE;

        newNode->prev = NULL;
        nodeList = newNode;
        eye = nodeList;
        strcpy(lastGreenNode->lex, newNode->lex);
        return;
    }

    while (lexName[asdf] != 0)
    {
        asdf++;
    }
    last = nodeList;

    if (nodeList->next != NULL)
    {

        while (t != PGMNAME)
        {

            if (strncmp(lexName, last->lex, asdf) != 0)
            {

                if (last->prev != NULL)
                {
                    t = last->prev->type;
                    last = last->prev;
                    if (t == 1)
                    {
                        t++;
                    }
                }
                else
                {

                    newNode = nodeList;
                    prevNode = newNode;
                    newNode->nextGreen = malloc(sizeof(token));
                    newNode = newNode->nextGreen;
                    newNode->next = NULL;
                    //newNode->nextGreen = NULL;

                    strcpy(newNode->lex, lexName);
                    newNode->type = type;

                    newNode->colorNode = GREENNODE;
                    nodeList = newNode;
                    newNode->next = NULL;
                    newNode->prev = prevNode;
                    //tempNewNode = newNode;

                    if(lastGreenNode!=NULL) {
                        tempGreenNode = lastGreenNode;
                        lastGreenNode->next = malloc(sizeof(token));
                        lastGreenNode = lastGreenNode->next;
                        strcpy(lastGreenNode->lex, newNode->lex);
                        lastGreenNode->prev = tempGreenNode;
                        
                    }
                    return;
                }
            }
            else
            {
                fprintf(listing, "Duplicate variable/function name in scope");
                return;
            }
            // t = nodeList->prev->type;
        }
    }

    while (t != PGMNAME)
    {

        if (strncmp(lexName, last->lex, asdf) != 0)
        {

            if (last->prev != NULL)
            {
                t = last->prev->type;
                last = last->prev;
                if (t == 1)
                {
                    t++;
                }
            }
            else
            {

                newNode = nodeList;
                prevNode = newNode;
                newNode->next = malloc(sizeof(token));
                newNode = newNode->next;
                newNode->next = NULL;

                strcpy(newNode->lex, lexName);
                newNode->type = type;

                newNode->colorNode = GREENNODE;
                nodeList = newNode;
                newNode->next = NULL;
                newNode->prev = prevNode;
                if(lastGreenNode!=NULL) {
                        tempGreenNode = lastGreenNode;
                        lastGreenNode->next = malloc(sizeof(token));
                        lastGreenNode = lastGreenNode->next;
                        strcpy(lastGreenNode->lex, newNode->lex);
                        lastGreenNode->prev = tempGreenNode;
                        
                    }
                return;
            }
        }
        else
        {
            fprintf(listing, "Duplicate variable/function name in scope");
            return;
        }
    }
}

void createBlueNode(char lexName[20], int type)
{
    //nodeList = eye;
    token *newBlueNode = (token *)malloc(sizeof(token));
    token *prevNode = malloc(sizeof(token));
    token *last = malloc(sizeof(token));
    token *param = malloc(sizeof(token));

    int asdf = 0;

    int t = type;

    if (nodeList == NULL)
    {

        strcpy(newBlueNode->lex, lexName);
        newBlueNode->type = type;

        newBlueNode->colorNode = BLUENODE;

        newBlueNode->prev = NULL;
        nodeList = newBlueNode;
        return;
    }

    while (lexName[asdf] != 0)
    {
        asdf++;
    }
    last = nodeList;

    if (nodeList->colorNode == GREENNODE)
    {
        if (strncmp(lexName, last->lex, asdf) != 0)
        {
            newBlueNode = nodeList;
            prevNode = newBlueNode;
            newBlueNode->next = malloc(sizeof(token));
            newBlueNode = newBlueNode->next;
            newBlueNode->next = NULL;

            strcpy(newBlueNode->lex, lexName);
            newBlueNode->type = type;

            newBlueNode->colorNode = BLUENODE;
            nodeList = newBlueNode;
            newBlueNode->next = NULL;
            newBlueNode->prev = prevNode;

            param = nodeList;
            eye = nodeList;

            if (nodeList->type == FUNPINT)
            {
                updateGreenNode();
                strncat(nodeList->parm, "5", asdf);
                //nodeList->parm[parmCount] = 5;
                getGreenBack();
                parmCount += 1;
                return;
            }
            if (nodeList->type == FUNPREAL)
            {
                updateGreenNode();
                strncat(nodeList->parm, "6", asdf);
                //nodeList->parm[parmCount] = 6;
                getGreenBack();
                parmCount += 1;
                return;
            }
            if (nodeList->type == FUNPAINT)
            {
                updateGreenNode();
                strncat(nodeList->parm, "7", asdf);
                arrayParam = 1;
                //nodeList->parm[parmCount] = 7;
                getGreenBack();
                parmCount += 1;
                return;
            }
            if (nodeList->type == FUNPAREAL)
            {
                updateGreenNode();
                strncat(nodeList->parm, "8", asdf);
                arrayParam = 1;
                //nodeList->parm[parmCount] = 8;
                getGreenBack();
                parmCount += 1;
                return;
            }
            return;
        }
    }
    while (last->colorNode != GREENNODE)
    {

        if (strncmp(lexName, last->lex, asdf) != 0)
        {
            last = last->prev;
            if (last->colorNode == GREENNODE)
            {
                //(strncmp(res->lex, *ptr, front - *ptr) == 0 && front - *ptr == strlen(res->lex))
                if (strncmp(lexName, last->lex, asdf) == 0 && asdf == strlen(last->lex))
                {
                    fprintf(listing, "Duplicate variable name in scope \n");
                    return;
                }
            }
        }
        else
        {
            fprintf(listing, "Duplicate variable name in scope \n");
            return;
        }
    }
    newBlueNode = nodeList;
    prevNode = newBlueNode;
    newBlueNode->next = malloc(sizeof(token));
    newBlueNode = newBlueNode->next;
    newBlueNode->next = NULL;

    strcpy(newBlueNode->lex, lexName);
    newBlueNode->type = type;

    newBlueNode->colorNode = BLUENODE;
    nodeList = newBlueNode;
    newBlueNode->next = NULL;
    newBlueNode->prev = prevNode;

    eye = nodeList;

    if (nodeList->type == FUNPINT)
    {
        updateGreenNode();
        strncat(nodeList->parm, "5", asdf);
        //nodeList->parm[parmCount] = 5;
        getGreenBack();
        parmCount += 1;
        return;
    }
    if (nodeList->type == FUNPREAL)
    {
        updateGreenNode();
        strncat(nodeList->parm, "6", asdf);
        //nodeList->parm[parmCount] = 6;
        getGreenBack();
        parmCount += 1;
        return;
    }
    if (nodeList->type == FUNPAINT)
    {
        updateGreenNode();
        strncat(nodeList->parm, "7", asdf);
        arrayParam = 1;
        //nodeList->parm[parmCount] = 7;
        getGreenBack();
        parmCount += 1;
        return;
    }
    if (nodeList->type == FUNPAREAL)
    {
        updateGreenNode();
        strncat(nodeList->parm, "8", asdf);
        arrayParam = 1;
        //nodeList->parm[parmCount] = 8;
        getGreenBack();
        parmCount += 1;
        return;
    }
    return;
}

void popGreenNode()
{

    eye = nodeList;
    while(strcmp(eye->lex, lastGreenNode->lex) != 0) 
    {
        eye = eye->prev;
    }
    //eye = lastGreenNode->prev;
    nodeList = eye;
    lastGreenNode = lastGreenNode->prev;
    /*
    eye = nodeList;
    while (eye->colorNode != GREENNODE)
    {
        eye = eye->prev;
    }
    nodeList = eye;*/
    //while(lastGreenNode)
}

void linkedId()
{

    char buffer2[72];
    FILE *reserved = fopen("idwords.txt", "r");

    token *id = malloc(sizeof(token));
    idList = id;

    while (fgets(buffer2, 72, reserved))
    {
        sscanf(buffer2, "%s %s %d %s %d /n", id->lex, id->tokenname, &id->type, id->attname, (int *)&id->types.address);
        id->next = malloc(sizeof(token));
        id = id->next;
    }

    id = idList;
    while (id->next != NULL)
    {
        fprintf(reserved, "%s %s %d %s %d \n", id->lex, id->tokenname, id->type, id->attname, (int)id->types.address);
        id = id->next;
    }
}

token *relopmachine(char **ptr)
{
    char *front = *ptr;
    char *back = *ptr;
    token *relop = malloc(sizeof(token));

    switch (*front)
    {
    case '<':
        front++;
        switch (*front)
        {
        case '=':
            strcpy(relop->lex, "<=");
            strcpy(relop->tokenname, "RELOP");
            relop->type = RELOP;
            strcpy(relop->attname, "LE");
            relop->types.att = LE;
            front++;
            b++;
            *ptr = front;
            globFront = front;
            return relop;

        case '>':
            strcpy(relop->lex, "<>");
            strcpy(relop->tokenname, "RELOP");
            relop->type = RELOP;
            strcpy(relop->attname, "NEQ");
            relop->types.att = NEQ;
            front++;
            b++;
            *ptr = front;
            globFront = front;
            return relop;

        default:
            strcpy(relop->lex, "<");
            strcpy(relop->tokenname, "RELOP");
            relop->type = RELOP;
            strcpy(relop->attname, "LT");
            relop->types.att = LT;
            //front--;
            b++;
            *ptr = front;
            globFront = front;
            return relop;
        }
    case '=':
        strcpy(relop->lex, "=");
        strcpy(relop->tokenname, "RELOP");
        relop->type = RELOP;
        strcpy(relop->attname, "EQ");
        relop->types.att = EQ;
        front++;
        b++;
        *ptr = front;
        globFront = front;
        return relop;
    case '>':
        front++;
        switch (*front)
        {
        case '=':
            strcpy(relop->lex, ">=");
            strcpy(relop->tokenname, "RELOP");
            relop->type = RELOP;
            strcpy(relop->attname, "GE");
            relop->types.att = GE;
            front++;
            b++;
            *ptr = front;
            globFront = front;
            return relop;

        default:
            strcpy(relop->lex, ">");
            strcpy(relop->tokenname, "RELOP");
            relop->type = RELOP;
            strcpy(relop->attname, "GT");
            relop->types.att = GT;
            *ptr = front;
            b++;
            globFront = front;
            return relop;
        }

    default:

        strncpy(relop->lex, back, 1);
        relop->lex[1] = '\0';
        strcpy(relop->tokenname, "LEXERR");
        relop->type = LEXERR;
        strcpy(relop->attname, "ERR1");
        relop->types.att = ERR1;
        front++;
        b++;
        *ptr = front;
        globFront = front;
        return relop;
    }
}

token *intmachine(char **ptr)
{
    err2 = 0;
    err3 = 0;
    err4 = 0;
    err5 = 0;
    err6 = 0;
    char *front = *ptr;
    char *back = *ptr;
    token *intToken = malloc(sizeof(token));

    front++;
    char leadingZero = *front;
    front--;

    if (*front == '0' && isdigit(leadingZero))
    {
        err2 = 1;
        while (isdigit(*front))
        {
            front++;
        }
        if ((front - *ptr) > 10)
        {
            err7 = 1;

            strncpy(intToken->lex, *ptr, front - *ptr);
            strcpy(intToken->tokenname, "LEXERR");
            intToken->type = LEXERR;
            strcpy(intToken->attname, "ERR7");
            intToken->types.att = ERR7;
            *ptr = front;
            globFront = front;
            return intToken;
        }

        strncpy(intToken->lex, *ptr, front - *ptr);
        strcpy(intToken->tokenname, "LEXERR");
        intToken->type = LEXERR;
        strcpy(intToken->attname, "ERR2");
        intToken->types.att = ERR2;
        *ptr = front;
        globFront = front;
        return intToken;
    }
    else if (isdigit(*front))
    {
        while (isdigit(*front))
        {
            //printf("This is ss number");
            front++;
        }
        if ((front - *ptr) > 10)
        {
            err7 = 1;
            strncpy(intToken->lex, *ptr, front - *ptr);
            strcpy(intToken->tokenname, "LEXERR");
            intToken->type = LEXERR;
            strcpy(intToken->attname, "ERR7");
            intToken->types.att = ERR7;
            *ptr = front;
            globFront = front;
            return intToken;
        }
        else
        {
            strncpy(intToken->lex, *ptr, front - *ptr);
            strcpy(intToken->tokenname, "NUM");
            intToken->type = NUM;
            strcpy(intToken->attname, "INTNUM");
            intToken->types.att = INTNUM;
            *ptr = front;
            globFront = front;
            return intToken;
        }
    }
    return relopmachine(ptr);
}

token *realmachine(char **ptr)
{
    err2 = 0;
    err3 = 0;
    err4 = 0;
    err5 = 0;
    err6 = 0;
    err9 = 0;

    int localB = 0;
    char *front = *ptr;
    //char *back = *ptr;
    token *realToken = malloc(sizeof(token));
    front++;
    char leadingZero = *front;
    front--;

    if (*front == '0' && isdigit(leadingZero))
    {
        err2 = 1;
        while (isdigit(*front) && (front - *ptr) < 5)
        {
            front++;
        }
        if (isdigit(*front))
        {
            err3 = 1;

            while (isdigit(*front))
            {
                front++;
            }
        }
        if (*front == '.')
        {
            front++;

            char *EDback2 = front;
            char *EDtemp2 = front;

            while (isdigit(*EDback2) && (EDback2 - EDtemp2) < 5)
            {
                EDback2++;
                front++;
            }

            if (isdigit(*front))
            {
                err4 = 1;

                while (isdigit(*front))
                {
                    front++;
                }

                strncpy(realToken->lex, *ptr, front - *ptr);
                strcpy(realToken->tokenname, "LEXERR");
                realToken->type = LEXERR;
                strcpy(realToken->attname, "ERR8");
                realToken->types.att = ERR8;
                *ptr = front;
                globFront = front;
                return realToken;
            }
            else
            {
                strncpy(realToken->lex, *ptr, front - *ptr);
                strcpy(realToken->tokenname, "LEXERR");
                realToken->type = LEXERR;
                strcpy(realToken->attname, "ERR2");
                realToken->types.att = ERR2;
                *ptr = front;
                globFront = front;
                return realToken;
            }
        }
        else
        {
            return intmachine(ptr);
        }
    }
    //else if (*front == '0')
    //{
     //   return intmachine(ptr);
    //}
    else if (isdigit(*front))
    {
        while (isdigit(*front) && (front - *ptr) < 5)
        {
            front++;
        }
        if (isdigit(*front))
        {
            err3 = 1;

            while (isdigit(*front))
            {
                front++;
            }

            if (*front == '.')
            {
                front++;

                char *EDback2 = front;
                char *EDtemp2 = front;

                while (isdigit(*EDback2) && (EDback2 - EDtemp2) < 5)
                {
                    EDback2++;
                    front++;
                }

                if (isdigit(*front))
                {
                    err4 = 1;

                    while (isdigit(*front))
                    {
                        front++;
                    }
                }
                else
                {
                    strncpy(realToken->lex, *ptr, front - *ptr);
                    strcpy(realToken->tokenname, "LEXERR");
                    realToken->type = LEXERR;
                    strcpy(realToken->attname, "ERR2");
                    realToken->types.att = ERR2;
                    *ptr = front;
                    globFront = front;
                    return realToken;
                }
            }
            else
            {
                return intmachine(ptr);
            }
        }

        else if (*front == '.')
        {
            front++;
            front++;
            char leadingZero2 = *front;
            front--;

            if(*front == '0' && isdigit(leadingZero2)) {
                while (isdigit(*front))
                {
                    front++;
                }
                err9 = 1;
                strncpy(realToken->lex, *ptr, front - *ptr);
                strcpy(realToken->tokenname, "LEXERR");
                realToken->type = LEXERR;
                strcpy(realToken->attname, "ERR");
                realToken->types.att = ERR9;
                *ptr = front;
                globFront = front;
                return realToken;
            }
            if (isdigit(*front))
            {
                char *EDback4 = front;
                char *EDtemp4 = front;
                while (isdigit(*EDback4) && (EDback4 - EDtemp4) < 5)
                {
                    EDback4++;
                    front++;
                }
            }
            else
            {
                return intmachine(ptr);
            }
            if (isdigit(*front))
            {
                err4 = 1;

                while (isdigit(*front))
                {
                    front++;
                }
                strncpy(realToken->lex, *ptr, front - *ptr);
                strcpy(realToken->tokenname, "LEXERR");
                realToken->type = LEXERR;
                strcpy(realToken->attname, "ERR8");
                realToken->types.att = ERR8;
                *ptr = front;
                globFront = front;
                return realToken;
            }

            else
            {
                strncpy(realToken->lex, *ptr, front - *ptr);
                strcpy(realToken->tokenname, "NUM");
                realToken->type = NUM;
                strcpy(realToken->attname, "REALNUM");
                realToken->types.att = REALNUM;
                *ptr = front;
                globFront = front;
                return realToken;
            }
        }
        else if (*front == '\0' || isblank(*front))
        {
            return intmachine(ptr);
        }
    }

    return intmachine(ptr);
}

token *longrealmachine(char **ptr)
{
    char *front = *ptr;
    //char *back = *ptr;
    token *realToken = malloc(sizeof(token));
    front++;
    char leadingZero = *front;
    front--;

    if (*front == '0' && isdigit(leadingZero))
    {
        err2 = 1;
        while (isdigit(*front) && (front - *ptr) < 5)
        {
            front++;
        }
        if (isdigit(*front))
        {
            err3 = 1;

            while (isdigit(*front))
            {
                front++;
            }
        }
        if (*front == '.')
        {
            front++;

            char *EDback2 = front;
            char *EDtemp2 = front;

            while (isdigit(*EDback2) && (EDback2 - EDtemp2) < 5)
            {
                EDback2++;
                front++;
            }

            if (isdigit(*front))
            {
                err4 = 1;

                while (isdigit(*front))
                {
                    front++;
                }
                if (isdigit(*front))
                {
                    return realmachine(ptr);
                }
            }
            if (*front == 'e' || *front == 'E')
            {
                front++;

                if (*front == '-' || *front == '+')
                {
                    front++;
                }

                if (*front == '0')
                {
                    err5 = 1;
                }

                char *EDback3 = front;
                char *EDtemp3 = front;
                while (isdigit(*EDback3) && (EDback3 - EDtemp3) < 2)
                {
                    EDback3++;
                    front++;
                }
                if (isdigit(*front))
                {
                    err6 = 1;
                }

                while (isdigit(*front))
                {
                    front++;
                }

                strncpy(realToken->lex, *ptr, front - *ptr);
                strcpy(realToken->tokenname, "LEXERR");
                realToken->type = LEXERR;
                strcpy(realToken->attname, "ERR2");
                realToken->types.att = ERR2;
                *ptr = front;
                globFront = front;
                return realToken;
            }
        }
        else
        {
            return realmachine(ptr);
        }
    }
    //else if (*front == '0')
    //{
     //   return intmachine(ptr);
    //}
    else if (isdigit(*front))
    {
        while (isdigit(*front) && (front - *ptr) < 5)
        {
            front++;
        }
        if (isdigit(*front))
        {
            err3 = 1;

            while (isdigit(*front))
            {
                front++;
            }

            if (*front == '.')
            {
                front++;

                char *EDback2 = front;
                char *EDtemp2 = front;

                while (isdigit(*EDback2) && (EDback2 - EDtemp2) < 5)
                {
                    EDback2++;
                    front++;
                }

                if (isdigit(*front))
                {
                    err4 = 1;

                    while (isdigit(*front))
                    {
                        front++;
                    }
                    if (isdigit(*front))
                    {
                        return realmachine(ptr);
                    }
                }
                if (*front == 'e' || *front == 'E')
                {
                    front++;

                    if (*front == '-' || *front == '+')
                    {
                        front++;
                    }

                    if (*front == '0')
                    {
                        err5 = 1;
                    }

                    char *EDback3 = front;
                    char *EDtemp3 = front;
                    while (isdigit(*EDback3) && (EDback3 - EDtemp3) < 2)
                    {
                        EDback3++;
                        front++;
                    }
                    if (isdigit(*front))
                    {
                        err6 = 1;
                    }

                    while (isdigit(*front))
                    {
                        front++;
                    }

                    strncpy(realToken->lex, *ptr, front - *ptr);
                    strcpy(realToken->tokenname, "LEXERR");
                    realToken->type = LEXERR;
                    strcpy(realToken->attname, "ERR8");
                    realToken->types.att = ERR8;
                    *ptr = front;
                    globFront = front;
                    return realToken;
                }
            }
            else
            {
                return realmachine(ptr);
            }
        }

        else if (*front == '.')
        {
            front++;
            front++;
            char leadingZero2 = *front;
            front--;

            if(*front == '0' && isdigit(leadingZero2)) {
                while (isdigit(*front))
                {
                    front++;
                }
                err9 = 1;
                strncpy(realToken->lex, *ptr, front - *ptr);
                strcpy(realToken->tokenname, "LEXERR");
                realToken->type = LEXERR;
                strcpy(realToken->attname, "ERR");
                realToken->types.att = ERR9;
                *ptr = front;
                globFront = front;
                return realToken;
            }
            if (isdigit(*front))
            {
                char *EDback4 = front;
                char *EDtemp4 = front;
                while (isdigit(*EDback4) && (EDback4 - EDtemp4) < 5)
                {
                    EDback4++;
                    front++;
                }
            }
            else
            {
                return realmachine(ptr);
            }
            if (isdigit(*front))
            {
                err4 = 1;

                while (isdigit(*front))
                {
                    front++;
                }

                if (*front == 'e' || *front == 'E')
                {
                    front++;

                    if (*front == '+' || *front == '-')
                    {
                        front++;
                    }
                    if (*front == '0')
                    {
                        err5 = 1;
                    }
                    char *EDback5 = front;
                    char *EDtemp5 = front;
                    while (isdigit(*EDback5) && (EDback5 - EDtemp5) < 2)
                    {
                        EDback5++;
                        front++;
                    }
                    if (isdigit(*front))
                    {
                        err6 = 1;

                        while (isdigit(*front))
                        {
                            front++;
                        }
                        strncpy(realToken->lex, *ptr, front - *ptr);
                        strcpy(realToken->tokenname, "LEXERR");
                        realToken->type = LEXERR;
                        strcpy(realToken->attname, "ERR8");
                        realToken->types.att = ERR8;
                        *ptr = front;
                        globFront = front;
                        return realToken;
                    }
                }
                else
                {
                    return realmachine(ptr);
                }
            }
            else if (*front == '\0' || isblank(*front))
            {
                return realmachine(ptr);
            }
            else if (*front == 'e' || *front == 'E')
            {
                front++;
                if (*front == '+' || *front == '-')
                {
                    front++;
                }
                if (*front == '0')
                {
                    err5 = 1;

                    char *EDback6 = front;
                    char *EDtemp6 = front;
                    while (isdigit(*EDback6) && (EDback6 - EDtemp6) < 2)
                    {
                        EDback6++;
                        front++;
                    }
                    if (isdigit(*front))
                    {
                        err6 = 1;
                    }
                    while (isdigit(*front))
                    {
                        front++;
                    }
                    strncpy(realToken->lex, *ptr, front - *ptr);
                    strcpy(realToken->tokenname, "LEXERR");
                    realToken->type = LEXERR;
                    strcpy(realToken->attname, "ERR8");
                    realToken->types.att = ERR8;
                    *ptr = front;
                    globFront = front;
                    return realToken;
                }
                else
                {
                    char *EDback7 = front;
                    char *EDtemp7 = front;
                    while (isdigit(*EDback7) && (EDback7 - EDtemp7) < 2)
                    {
                        EDback7++;
                        front++;
                    }
                    if (isdigit(*front))
                    {
                        while (isdigit(*front))
                        {
                            front++;
                        }
                        err6 = 1;
                        strncpy(realToken->lex, *ptr, front - *ptr);
                        strcpy(realToken->tokenname, "LEXERR");
                        realToken->type = LEXERR;
                        strcpy(realToken->attname, "ERR2");
                        realToken->types.att = ERR2;
                        *ptr = front;
                        globFront = front;
                        return realToken;
                    }
                    else
                    {
                        strncpy(realToken->lex, *ptr, front - *ptr);
                        strcpy(realToken->tokenname, "NUM");
                        realToken->type = NUM;
                        strcpy(realToken->attname, "LONGREAL");
                        realToken->types.att = LONGREAL;
                        *ptr = front;
                        globFront = front;
                        return realToken;
                    }
                }
            }
        }
    }
    return realmachine(ptr);
}

token *catchallmachine(char **ptr)
{
    char *front = *ptr;
    char *back = *ptr;
    token *catchall = malloc(sizeof(token));

    switch (*front)
    {
    case '(':
        strcpy(catchall->lex, "(");
        strcpy(catchall->tokenname, "OP");
        catchall->type = OP;
        strcpy(catchall->attname, "NIL");
        catchall->types.att = NIL;
        front++;
        *ptr = front;
        globFront = front;
        b++;
        return catchall;
    case ')':
        strcpy(catchall->lex, ")");
        strcpy(catchall->tokenname, "CP");
        catchall->type = CP;
        strcpy(catchall->attname, "NIL");
        catchall->types.att = NIL;
        front++;
        *ptr = front;
        globFront = front;
        b++;
        return catchall;
    case ',':
        strcpy(catchall->lex, ",");
        strcpy(catchall->tokenname, "COMMA");
        catchall->type = COMMA;
        strcpy(catchall->attname, "NIL");
        catchall->types.att = NIL;
        front++;
        *ptr = front;
        globFront = front;
        b++;
        return catchall;
    case ';':
        strcpy(catchall->lex, ";");
        strcpy(catchall->tokenname, "SEMICOLON");
        catchall->type = SEMICOLON;
        strcpy(catchall->attname, "NIL");
        catchall->types.att = NIL;
        front++;
        *ptr = front;
        globFront = front;
        globBack = front;
        b++;
        return catchall;
    case '[':
        strcpy(catchall->lex, "[");
        strcpy(catchall->tokenname, "OB");
        catchall->type = OB;
        strcpy(catchall->attname, "NIL");
        catchall->types.att = NIL;
        front++;
        *ptr = front;
        globFront = front;
        b++;
        return catchall;
    case ']':
        strcpy(catchall->lex, "]");
        strcpy(catchall->tokenname, "CB");
        catchall->type = CB;
        strcpy(catchall->attname, "NIL");
        catchall->types.att = NIL;
        front++;
        *ptr = front;
        globFront = front;
        b++;
        return catchall;
    case '+':
        strcpy(catchall->lex, "+");
        strcpy(catchall->tokenname, "ADDOP");
        catchall->type = ADDOP;
        strcpy(catchall->attname, "PLUS");
        catchall->types.att = PLUS;
        front++;
        *ptr = front;
        globFront = front;
        b++;
        return catchall;
    case '-':
        strcpy(catchall->lex, "-");
        strcpy(catchall->tokenname, "ADDOP");
        catchall->type = ADDOP;
        strcpy(catchall->attname, "MINUS");
        catchall->types.att = MINUS;
        front++;
        *ptr = front;
        globFront = front;
        b++;
        return catchall;
    case '*':
        strcpy(catchall->lex, "*");
        strcpy(catchall->tokenname, "MULOP");
        catchall->type = MULOP;
        strcpy(catchall->attname, "MULTIPLY");
        catchall->types.att = MULTIPLY;
        front++;
        *ptr = front;
        globFront = front;
        b++;
        return catchall;
    case '/':
        strcpy(catchall->lex, "/");
        strcpy(catchall->tokenname, "MULOP");
        catchall->type = MULOP;
        strcpy(catchall->attname, "DIVIDE");
        catchall->types.att = DIVIDE;
        front++;
        *ptr = front;
        globFront = front;
        b++;
        return catchall;
    case '.':
        front++;
        b++;
        switch (*front)
        {
        case '.':
            strcpy(catchall->lex, "..");
            strcpy(catchall->tokenname, "DOTDOT");
            catchall->type = DOTDOT;
            strcpy(catchall->attname, "NIL");
            catchall->types.att = NIL;
            front++;
            *ptr = front;
            globFront = front;
            b++;
            return catchall;
        default:
            strcpy(catchall->lex, ".");
            strcpy(catchall->tokenname, "DOT");
            catchall->type = DOT;
            strcpy(catchall->attname, "NIL");
            catchall->types.att = NIL;
            *ptr = front;
            globFront = front;
            return catchall;
        }
    case ':':
        front++;
        b++;
        switch (*front)
        {
        case '=':
            strcpy(catchall->lex, ":=");
            strcpy(catchall->tokenname, "ASSIGNOP");
            catchall->type = ASSIGNOP;
            strcpy(catchall->attname, "NIL");
            catchall->types.att = NIL;
            front++;
            *ptr = front;
            globFront = front;
            b++;
            return catchall;
        default:
            strcpy(catchall->lex, ":");
            strcpy(catchall->tokenname, "COLON");
            catchall->type = COLON;
            strcpy(catchall->attname, "NIL");
            catchall->types.att = NIL;
            //front++;
            *ptr = front;
            globFront = front;
            return catchall;
        }
    default:
        return longrealmachine(ptr);
    }
}

token *idmachine(char **ptr)
{

    char buffer2[72];
    FILE *idwords = fopen("idwords.txt", "a+");

    token *id = malloc(sizeof(token));
    //idList = id;

    while (fgets(buffer2, 72, idwords))
    {
        sscanf(buffer2, "%s %s %d %s %d", id->lex, id->tokenname, &id->type, id->attname, (int *)&id->types.address);
        id->next = malloc(sizeof(token));
        id = id->next;
    }
    id = idList;
    //id->next = malloc(sizeof(token));
    //id->next = NULL;
    char *front = *ptr;
    char *idptr = *ptr;

    if (!isalpha(*front))
    {
        //printf("Not a letter \n");
        return catchallmachine(ptr);
    }
    if (isalnum(*front))
    {
        //b++;
        while (isalnum(*front))
        {
            front++;
        }
        if ((front - *ptr) > 10)
        {
            while (isalnum(*front))
            {
                front++;
            }
            strncpy(id->lex, *ptr, front - *ptr);
            strcpy(id->tokenname, "LEXERR");
            id->type = LEXERR;
            strcpy(id->attname, "ERR3");
            id->types.att = ERR3;
            *ptr = front;
            return id;
        }

        while (id->next != NULL)
        {
            if (strncmp(id->lex, *ptr, front - *ptr) == 0 && front - *ptr == strlen(id->lex))
            {
                *ptr = front;
                globFront = front;
                test = 1;
                return id;
            }
            id = id->next;
        }
        id = idList;

        //id->next = NULL;

        //id = id->next;
        //id = id->next;
        while (id->next != NULL)
        {
            id = id->next;
        }
        strncpy(id->lex, *ptr, front - *ptr);
        strcpy(id->tokenname, "ID");
        id->type = ID;
        strcpy(id->attname, "ADDRESS");
        id->types.address = malloc(sizeof(void));

        //printf("its a match \n");

        fprintf(idwords, "%s %s %d %s %d \n", id->lex, id->tokenname, id->type, id->attname, (int)id->types.address);
        id->next = malloc(sizeof(token));
        globFront = front;
        *ptr = front;
        globFront = front;
        id = idList;
        return id;
    }

    else
    {
        return catchallmachine(ptr);
    }
}

token *resmachine(char **ptr)
{
    token *res = malloc(sizeof(token));

    res = tokenList;

    char *front = *ptr;
    char *word = *ptr;

    token *rettoken = malloc(sizeof(token));

    if (!isalpha(*front))
    {
        //printf("Not a letter \n");
        return idmachine(ptr);
    }

    while (isalpha(*front))
    {
        front++;
        b++;
    }
    while (res->next != NULL)
    {
        if (strncmp(res->lex, *ptr, front - *ptr) == 0 && front - *ptr == strlen(res->lex))
        {
            strncpy(rettoken->lex, *ptr, front - *ptr);
            switch (*word)
            {
            case 'v':
                //strcpy(rettoken->lex,"var");
                strcpy(rettoken->tokenname, "VAR");
                rettoken->type = VAR;
                strcpy(rettoken->attname, "NIL");
                rettoken->types.att = NIL;
                //printf("its a match \n");
                word++;
                *ptr = front;
                globFront = front;
                return rettoken;
            case 'p':
                strcpy(rettoken->tokenname, "PROG");
                rettoken->type = PROG;
                strcpy(rettoken->attname, "NIL");
                rettoken->types.att = NIL;
                //printf("its a match \n");
                word++;
                *ptr = front;
                globFront = front;
                res = res->next;
                return rettoken;
            case 'r':
                strcpy(rettoken->tokenname, "REAL");
                rettoken->type = REAL;
                strcpy(rettoken->attname, "NIL");
                rettoken->types.att = NIL;
                //printf("its a match \n");
                *ptr = front;
                globFront = front;
                return rettoken;
            case 'f':
                strcpy(rettoken->tokenname, "FUNCTION");
                rettoken->type = FUNCTION;
                strcpy(rettoken->attname, "NIL");
                rettoken->types.att = NIL;
                //printf("its a match \n");
                *ptr = front;
                globFront = front;
                return rettoken;
            case 'b':
                strcpy(rettoken->tokenname, "BEGIN");
                rettoken->type = BEGIN;
                strcpy(rettoken->attname, "NIL");
                rettoken->types.att = NIL;
                //printf("its a match \n");
                *ptr = front;
                globFront = front;
                return rettoken;
            case 'm':
                strcpy(rettoken->tokenname, "MULOP");
                rettoken->type = MULOP;
                strcpy(rettoken->attname, "MOD");
                rettoken->types.att = MOD;
                //printf("its a match \n");
                *ptr = front;
                globFront = front;
                return rettoken;
            case 'e':
                word++;
                switch (*word)
                {
                case 'l':
                    strcpy(rettoken->tokenname, "ELSE");
                    rettoken->type = ELSE;
                    strcpy(rettoken->attname, "NIL");
                    rettoken->types.att = NIL;
                    //printf("its a match \n");
                    *ptr = front;
                    globFront = front;
                    return rettoken;
                default:
                    strcpy(rettoken->tokenname, "END");
                    rettoken->type = END;
                    strcpy(rettoken->attname, "NIL");
                    rettoken->types.att = NIL;
                    //printf("its a match \n");
                    *ptr = front;
                    globFront = front;
                    return rettoken;
                }
            case 'i':
                word++;
                switch (*word)
                {
                case 'f':
                    strcpy(rettoken->tokenname, "IF");
                    rettoken->type = IF;
                    strcpy(rettoken->attname, "NIL");
                    rettoken->types.att = NIL;
                    //printf("its a match \n");
                    *ptr = front;
                    globFront = front;
                    return rettoken;
                default:
                    strcpy(rettoken->tokenname, "INTEGER");
                    rettoken->type = INTEGER;
                    strcpy(rettoken->attname, "NIL");
                    rettoken->types.att = NIL;
                    //printf("its a match \n");
                    *ptr = front;
                    globFront = front;
                    return rettoken;
                }
            case 't':
                strcpy(rettoken->tokenname, "THEN");
                rettoken->type = THEN;
                strcpy(rettoken->attname, "NIL");
                rettoken->types.att = NIL;
                //printf("its a match \n");
                *ptr = front;
                globFront = front;
                return rettoken;
            case 'w':
                strcpy(rettoken->tokenname, "WHILE");
                rettoken->type = WHILE;
                strcpy(rettoken->attname, "NIL");
                rettoken->types.att = NIL;
                //printf("its a match \n");
                *ptr = front;
                globFront = front;
                return rettoken;
            case 'd':
                word++;
                switch (*word)
                {
                case 'i':
                    strcpy(rettoken->tokenname, "MULOP");
                    rettoken->type = MULOP;
                    strcpy(rettoken->attname, "DIV");
                    rettoken->types.att = DIV;
                    //printf("its a match \n");
                    *ptr = front;
                    globFront = front;
                    return rettoken;
                default:
                    strcpy(rettoken->tokenname, "DO");
                    rettoken->type = DO;
                    strcpy(rettoken->attname, "NIL");
                    rettoken->types.att = NIL;
                    //printf("its a match \n");
                    *ptr = front;
                    globFront = front;
                    return rettoken;
                }
            case 'n':
                strcpy(rettoken->tokenname, "NOT");
                rettoken->type = NOT;
                strcpy(rettoken->attname, "NIL");
                rettoken->types.att = NIL;
                //printf("its a match \n");
                *ptr = front;
                globFront = front;
                return rettoken;
            case 'a':
                word++;
                switch (*word)
                {
                case 'n':
                    strcpy(rettoken->tokenname, "MULOP");
                    rettoken->type = MULOP;
                    strcpy(rettoken->attname, "AND");
                    rettoken->types.att = AND;
                    //printf("its a match \n");
                    *ptr = front;
                    globFront = front;
                    return rettoken;
                default:
                    strcpy(rettoken->tokenname, "ARRAY");
                    rettoken->type = ARRAY;
                    strcpy(rettoken->attname, "NIL");
                    rettoken->types.att = NIL;
                    //printf("its a match \n");
                    *ptr = front;
                    globFront = front;
                    return rettoken;
                }
            case 'o':
                word++;
                switch (*word)
                {
                case 'r':
                    strcpy(rettoken->tokenname, "ADDOP");
                    rettoken->type = ADDOP;
                    strcpy(rettoken->attname, "OR");
                    rettoken->types.att = OR;
                    //printf("its a match \n");
                    *ptr = front;
                    globFront = front;
                    return rettoken;
                default:
                    strcpy(rettoken->tokenname, "OF");
                    rettoken->type = OF;
                    strcpy(rettoken->attname, "NIL");
                    rettoken->types.att = NIL;
                    //printf("its a match \n");
                    *ptr = front;
                    globFront = front;
                    return rettoken;
                }

            default:
                return catchallmachine(ptr);
            }
        }

        res = res->next;
    }
    return idmachine(ptr);
}

token *whitemachine(char **ptr)
{
    endOfLine = 0;
    token *rettoken = malloc(sizeof(token));
    char *front = *ptr;

    while (*front == ' ' || *front == '\t')
    {
        front++;
        *ptr = front;
        b++;
    }

    while (*front == '\n' || *front == '\0')
    {
        endOfLine = 1;
        return NULL;
    }
    return resmachine(ptr);
}

token *gettoken()
{

    //char *go = gFRONT;
    //globFront = gFRONT;
    char *temp;
    int after = 0;
    char *front;
    token *tokGlob;
    token *eof = malloc(sizeof(struct token));
    char *before;

    //listing = fopen("listing.txt", "w");
    //fgets(buffer,72,input);

    //if(fgets(buffer, 72, input)) {
    //temp = globBack;
    if (*ptr == '\n' || *ptr == '\0')
    {
        b++;
        temp = ptr;
        while (*temp == '\n')
        {
            fgets(buffer, 72, input);
            temp = buffer;
            b = 0;
            nL = 1;
            newLine = 1;
        }
    }

    if (buffer[b] != '\0')
    {

        // if count
        after = 0;
        if (newLine == 1)
        {
            if (count > 0)
            {
                fprintf(listing, "\n%d.    %s ", i, buffer);
                //after = 1;
            }
            else
            {
                fprintf(listing, "%d.    %s ", i, buffer);
            }
            i++;
            i2++;
        }
        newLine++;
        ptr = buffer;
        if (count == 0)
        {
            globFront = ptr;
            globBack = ptr;
        }
        if (nL == 0)
        {
            ptr = globFront;
        }
        nL = 0;
        count++;

        before = ptr;
        tokGlob = whitemachine(&ptr);
        nLine++;

        if (*ptr == '\0' && *before != '.')
        {
            strcpy(eof->lex, "EOF");
            strcpy(eof->tokenname, "ENDFILE");
            eof->type = ENDFILE;
            strcpy(eof->attname, "NIL");
            eof->types.att = NIL;
            fprintf(tokenOutput, "%d.    %s %s %d %s %d \n", i, eof->lex, eof->tokenname, eof->type, eof->attname, eof->types.att);
            return eof;
        }

        fprintf(tokenOutput, "%d.     %s %s %d %s %d \n", i2, tokGlob->lex, tokGlob->tokenname, tokGlob->type, tokGlob->attname, tokGlob->types.att);

        if (tokGlob->type == LEXERR)
        {
            if (tokGlob->types.att == ERR1)
            {
                //count++;
                if (count == 1 || after == 1)
                {
                    fprintf(listing, "LEXERR: Unknown symbol:     %s", tokGlob->lex);
                }
                else
                {
                    fprintf(listing, "\nLEXERR: Unknown symbol:     %s", tokGlob->lex);
                }
                after = 0;
            }
            if (tokGlob->types.att == ERR3)
            {
                if (count == 1 || after == 1)
                {
                    fprintf(listing, "LEXERR: ID to large     %s", tokGlob->lex);
                }
                else
                {
                    fprintf(listing, "\nLEXERR: ID to large     %s", tokGlob->lex);
                }
                after = 0;
            }

            if (err2 == 1)
            {
                if (count == 1 || after == 1)
                {
                    fprintf(listing, "LEXERR: Leading Zero before decimal     %s", tokGlob->lex);
                }
                else
                {
                    fprintf(listing, "\nLEXERR: Leading Zero before decimal     %s", tokGlob->lex);
                }
                after = 0;
                err2 = 0;
            }
            if (err3 == 1)
            {
                if (count == 1 || after == 1)
                {
                    fprintf(listing, "LEXERR: Number before decimal point is greater than 5 characters    %s", tokGlob->lex);
                }
                else
                {
                    fprintf(listing, "\nLEXERR: Number before decimal point is greater than 5 characters    %s", tokGlob->lex);
                }
                after = 0;
                err3 = 0;
            }
            if (err4 == 1)
            {
                if (count == 1 || after == 1)
                {
                    fprintf(listing, "LEXERR: Number after decimal point is greater than 5 characters     %s", tokGlob->lex);
                }
                else
                {
                    fprintf(listing, "\nLEXERR: Number after decimal point is greater than 5 characters     %s", tokGlob->lex);
                }
                err4 = 0;
                after = 0;
            }
            if (err5 == 1)
            {
                if (count == 1 || after == 1)
                {
                    fprintf(listing, "LEXERR: Leading zero in the exponent   %s", tokGlob->lex);
                }
                else
                {
                    fprintf(listing, "\nLEXERR: Leading zero in the exponent   %s", tokGlob->lex);
                }
                after = 0;
                err5 = 0;
            }
            if (err6 == 1)
            {
                if (count == 1 || after == 1)
                {
                    fprintf(listing, "LEXERR: Numbers after exponent exceed 2 characters  %s", tokGlob->lex);
                }
                else
                {
                    fprintf(listing, "\nLEXERR: Numbers after exponent exceed 2 characters  %s", tokGlob->lex);
                }
                after = 0;
                err6 = 0;
            }
            if (err7 == 1)
            {
                if (count == 1 || after == 1)
                {
                    fprintf(listing, "LEXERR: Int is greater than 10 digits   %s", tokGlob->lex);
                }
                else
                {
                    fprintf(listing, "\nLEXERR: Int is greater than 10 digits   %s", tokGlob->lex);
                }
                after = 0;
                err7 = 0;
            }
            if (err9 == 1)
            {
                if (count == 1 || after == 1)
                {
                    fprintf(listing, "LEXERR: Leading 0 after decimal   %s\n", tokGlob->lex);
                }
                else
                {
                    fprintf(listing, "\nLEXERR: Leading 0 after decimal   %s", tokGlob->lex);
                }
                after = 0;
                err7 = 0;
            }
        }

        return tokGlob;
    }

    else
    {
        //token *eof = malloc(sizeof(struct token));
        strcpy(eof->lex, "EOF");
        strcpy(eof->tokenname, "ENDFILE");
        eof->type = ENDFILE;
        strcpy(eof->attname, "NIL");
        eof->types.att = NIL;
        fprintf(tokenOutput, "%d.    %s %s %d %s %d \n", i, eof->lex, eof->tokenname, eof->type, eof->attname, eof->types.att);
        return eof;
    }
}

int arrayErr(int fctrTail_i, int exp_type)
{
    int fctrTail_t;
    if (fctrTail_i == ERRSTAR || exp_type == ERRSTAR)
    {
        fctrTail_t = ERR;
        return fctrTail_t;
    }
    else if ((fctrTail_i == AINT || fctrTail_i == FUNPAINT) && (exp_type == INTNUM || exp_type == INTEGER))
    { //double check
        fctrTail_t = AINT;      ////////////////
        return fctrTail_t;
    }
    else if ((fctrTail_i == AREAL || fctrTail_i == FUNPAREAL) && (exp_type == INTNUM || exp_type == INTEGER))
    { //double check
        fctrTail_t = AREAL;     /////////////////
        return fctrTail_t;
    }
    else
    {
        fctrTail_t = ERR;
        fprintf(listing, "SEMERR: array var does not exist\n");
        return fctrTail_t;
    }
}

int getType(token *gettok)
{
    int type;
    token *typeList;
    //typeList = malloc(sizeof(token));
    typeList = nodeList;
    //isitEmpty(typeList);
    if (!typeList)
    {
        return ERR;
    }
    while ((strcmp(gettok->lex, typeList->lex) != 0) && (typeList->type != PGMNAME))
    {
        typeList = typeList->prev;
    }

    if (strcmp(gettok->lex, typeList->lex) == 0)
    {
        type = typeList->type;
        if (type == 9)
        {
            type = typeList->resType;
            func = 1;
        }
        return type;
    }
    else
    {
        fprintf(listing, "SEMERR: Variable not declared\n");
        return SEMERR;
    }
}

void getParam(token *gettok)
{
    char p[10];
    int type;
    token *typeList;
    typeList = nodeList;

    while ((strcmp(gettok->lex, typeList->lex) != 0) || typeList->type == PGMNAME)
    {
        typeList = typeList->prev;
    }

    if (strcmp(gettok->lex, typeList->lex) == 0)
    {
        
        strcpy(param, typeList->parm);
        //return p;
        //strcat(param, p);
    }
    else
    {
        fprintf(listing, "SEMERR: Variable not declared\n");
    }
}

int notfn(int t)
{
    int f_type;
    switch (t)
    {
    case BOOL:
        f_type = BOOL;
        return f_type;

    case ERR:
        f_type = ERR;
        return f_type;
    default:
        f_type = ERR;
        fprintf(listing, "SEMERR: Expecting BOOL\n");
        return f_type;
    }
}

int mulopErr(int inh, int type)
{
    int retType;
    if (inh == ERRSTAR || type == ERRSTAR || inh == ERR || type == ERR)
    {
        retType = ERR;
        return retType;
    }
    else if ((inh == INTNUM || inh == FUNPINT || inh == INTEGER) && (type == INTNUM || type == FUNPINT || type == INTEGER))
    {
        retType = INTNUM;
        return retType;
    }
    else if ((inh == REAL || inh == FUNPREAL || inh == REALNUM) && (type == REAL || type == FUNPREAL || type == REALNUM))
    {
        retType = REAL;
        return retType;
    }
    else if ((inh == BOOL && type == BOOL))
    {
        retType = BOOL;
        return retType;
    }
    else
    {
        retType = ERR;
        fprintf(listing, "SEMERR: Cannot complete mathematical operations with different types\n");
        return retType;
    }
}

int addopErr(int inh, int type)
{
    int retType;
    if (inh == ERRSTAR || type == ERRSTAR || inh == ERR || type == ERR)
    {
        retType = ERR;
        return retType;
    }
    else if ((inh == INTNUM || inh == FUNPINT || inh == INTEGER) && (type == INTNUM || type == FUNPINT || type == INTEGER))
    { //check
        retType = INTNUM;
        return retType;
    }
    else if ((inh == REAL || inh == FUNPREAL || inh == REALNUM) && (type == REAL || type == FUNPREAL || type == REALNUM))
    { //check
        retType = REAL;
        return retType;
    }
    else if ((inh == BOOL && type == BOOL))
    {
        retType = BOOL;
        return retType;
    }
    else
    {
        retType = ERR;
        fprintf(listing, "SEMERR: Cannot complete addop func on different types\n");
        return retType;
    }
}

int relopfn(int inh, int type)
{
    int retType;
    if (inh == ERRSTAR|| type == ERRSTAR)
    {
        retType = ERR;
        return retType;
    }
    /*
    else if ((type == INTNUM || type == REAL || type == AINT || type == AREAL || type == REALNUM || type == INTEGER) && inh == type) {
        retType = BOOL;
        return retType;
    }
    */
    else if ((inh == INTNUM || inh == FUNPINT || inh == INTEGER || inh == AINT) && (type == INTNUM || type == FUNPINT || type == INTEGER || type == AINT))
    { //check
        retType = BOOL;
        return retType;
    }
    else if ((inh == REAL || inh == FUNPREAL || inh == REALNUM || inh == AREAL) && (type == REAL || type == FUNPREAL || type == REALNUM || type == AREAL))
    { //check
        retType = BOOL;
        return retType;
    }
    else
    {
        retType = ERR;
        fprintf(listing, "SEMERR: Unable to compare different types\n");
        return retType;
    }
}

void match(int t)
{
    if (tok->type == t && tok->type == ENDFILE)
    {
        printf("Parse Complete!.\n");
        return;
    }
    else if (tok->type == t && tok->type != ENDFILE)
    {
        tok = gettoken();
    }
    else if (tok->type != t)
    {
        printf("%s %d", "SYNERR: EXPECTING ", t);
        tok = gettoken();
    }
}

int signfn(int t)
{
    int sexp_type_i;
    if (t == ERRSTAR || t == ERR)
    {
        sexp_type_i = ERR;
        return sexp_type_i;
    }
    else if (t == INTNUM)
    {
        sexp_type_i = INTNUM;
        return sexp_type_i;
    }
    else if (t == REALNUM)
    {
        sexp_type_i = REAL;
        return sexp_type_i;
    }
    else
    {
        sexp_type_i = ERR;
        fprintf(listing, "SEMERR: +/- needs to proceded a number\n");
        return sexp_type_i;
    }
}

int ifErr(int t)
{
    int retType;
    if (t == ERRSTAR || t == ERR)
    {
        retType = ERR;
        return retType;
    }
    else if (t == BOOL)
    {
        retType = OK;
        return retType;
    }
    else
    {
        retType = ERR;
        fprintf(listing, "SEMRR: If statment must compare BOOL\n");
        return retType;
    }
}

int whileErr(int t)
{
    int retType;
    if (t == ERRSTAR || t == ERR)
    {
        retType = ERR;
        return retType;
    }
    else if (t == BOOL)
    {
        retType = OK;
        return retType;
    }
    else
    {
        retType = ERR;
        fprintf(listing, "SEMERR: While statment must compare BOOL\n");
        return retType;
    }
}

int stmtErr(int var_type, int expr_type)
{
    int retType;
    if (var_type == ERRSTAR || expr_type == ERRSTAR || var_type == ERR || expr_type == ERR)
    {
        retType = ERR;
        return retType;
    }
    else if (var_type == expr_type || (var_type - 22) == expr_type || (var_type == FUNPINT && expr_type == INTEGER) 
    || (var_type == REAL && expr_type == REALNUM) || (var_type == REALNUM && expr_type == REAL || (var_type == AINT && expr_type == INTNUM) 
    || (var_type == INTNUM && expr_type == AINT) || (var_type == INTEGER && expr_type == AINT) || (var_type == AINT && expr_type == INTEGER)
    || (var_type == AREAL && expr_type == REALNUM) || (var_type == REALNUM && expr_type == AREAL) || (var_type == REAL && expr_type == AREAL) 
    || (var_type == AREAL && expr_type == REAL)))
    {
        retType = OK;
        return retType;
    }
    else
    {
        retType = ERR;
        fprintf(listing, "SEMERR: Unable to assign mixed types to each other\n");
        return retType;
    }
}

int checkParam(int receivedParam, char p[10])
{
    //int i = 0;
    int retType;

    if (receivedParam == ERRSTAR)
    {
        retType = ERRSTAR;
        return retType;
    }
    if (receivedParam == atoi(&p[parmCheck]))
    {
        retType = OK;
        return retType;
    }
    else
    {

        retType = ERR;
        fprintf(listing, "SEMERR: Actual function parameters do not match formal parameters\n");
        return retType;
    }
}

int arrayFun2(int arrErr, int arrType, int num1, int num2)
{
    int retType;
    int diff = num2 - num1;
    if (arrType == ERRSTAR || arrType == ERRSTAR || num1 == ERRSTAR || num2 == ERRSTAR)
    {
        retType = ERR;
        return retType;
    }

    else if (arrErr == OK && arrType == INTEGER)
    {
        retType = AINT;
        offset2 = (diff + 1) * 4;
        return retType;
    }
    else if (arrErr == OK && arrType == REAL)
    {
        retType = AREAL;
        offset2 = (diff + 1) * 8;
        return retType;
    }
    else
    {
        retType = ERR;
        fprintf(listing, "SEMERR: Incorrect array declaration\n");
        return retType;
    }
}

int concat(int a, int b)
{
    char str1[10];
    char str2[10];

    sprintf(str1, "%d", a);
    sprintf(str2, "%d", b);

    strcat(str1, str2);

    int ret = atoi(str1);
    return ret;
}

int arrayFun1(int num1, int num2, int num1_t, int num2_t)
{
    int retType;
    int diff = num2 - num1;
    if (num1 == ERRSTAR || num2 == ERRSTAR || num1_t == ERRSTAR || num2_t == ERRSTAR)
    {
        retType = ERR;
        return retType;
    }
    else if (num1_t == INTNUM && num2_t == INTNUM && diff > 0)
    {
        retType = OK;
        return retType;
    }
    else if (diff < 0)
    {
        retType = ERR;
        fprintf(listing, "SEMERR: Array declaration should list smaller number before bigger\n");
        return retType;
    }
    else if (num1 != INTNUM || num2 != INTNUM)
    {
        retType = ERR;
        fprintf(listing, "SEMERR: Incorrect array declaration, needs to include integers within brackets\n");
        return retType;
    }
    else
    {
        retType = ERR;
        fprintf(listing, "SEMERR: Incorrect array declaration\n");
        return retType;
    }
}
void sign()
{
    switch (tok->type)
    {
    case PLUS:
        match(PLUS);
        break;
    case MINUS:
        match(MINUS);
        break;

    default:
        fprintf(listing, "SYNERR: Expecting plus or minus. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != NUM && tok->type != OP && tok->type != NOT && tok->type != ID)
        {
            tok = gettoken();
        }
    }
}

int fctrTail(int fctrTail_i)
{
    int exp_type;
    int fctr_tail_type;
    int elist_t;
    int errReturn;
    int checkErr;
    //char param[10];
    switch (tok->type)
    {
    case OB:
        match(OB);
        exp_type = expr();
        fctr_tail_type = arrayErr(fctrTail_i, exp_type);
        match(CB);
        if((fctrTail_i == fctr_tail_type) && eListCheck == 1) {
            if(fctrTail_i == AINT) {
                fctr_tail_type = INTEGER;
            }
            else {
                fctr_tail_type = REAL;
            }
        }
        return fctr_tail_type;
        break;
    case OP: //checks
        match(OP);
        eListCheck = 1;
        elist_t = elist();
        match(CP);
        eListCheck = 0;
        if(elist_t == ERRSTAR) {
            checkErr = checkParam(ERRSTAR, param);
            return checkErr;
        }
        else {
        checkParam(elistOutput, param);
        }
        fctr_tail_type = fctrTail_i;
        return fctr_tail_type;
        break;
    case MULOP:
        fctr_tail_type = fctrTail_i;
        return fctr_tail_type;
        break;
    case ADDOP:
        fctr_tail_type = fctrTail_i;
        return fctr_tail_type;
        break;
    case RELOP:
        fctr_tail_type = fctrTail_i;
        return fctr_tail_type;
        break;
    case SEMICOLON:
        fctr_tail_type = fctrTail_i;
        return fctr_tail_type;
        break;
    case END:
        fctr_tail_type = fctrTail_i;
        return fctr_tail_type;
        break;
    case DO:
        fctr_tail_type = fctrTail_i;
        return fctr_tail_type;
        break;
    case THEN:
        fctr_tail_type = fctrTail_i;
        return fctr_tail_type;
        break;
    case CB:
        fctr_tail_type = fctrTail_i;
        return fctr_tail_type;
        break;
    case COMMA:
        fctr_tail_type = fctrTail_i;
        return fctr_tail_type;
        break;
    case CP:
        fctr_tail_type = fctrTail_i;
        return fctr_tail_type;
        break;
    case ELSE:
        fctr_tail_type = fctrTail_i;
        return fctr_tail_type;
        break;
    default:
        fprintf(listing, "SYNERR: Expecting mulop, addop, relop, ; ,  end, do, then, ] , , , ) , or else. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != MULOP && tok->type != ADDOP && tok->type != RELOP && tok->type != SEMICOLON && tok->type != END && tok->type != DO && tok->type != THEN && tok->type != CB && tok->type != COMMA && tok->type != CP && tok->type != ELSE)
        {
            tok = gettoken();
        }
        errReturn = ERRSTAR;
        return errReturn;
    }
    return ERR;
}

int fctr()
{
    int f_type;
    int f_tail_i;
    int f_type2;
    int resType;
    int errReturn;
    switch (tok->type)
    {
    case NUM:
        f_type = tok->types.att;
        match(NUM);
        return f_type;
        break;
    case OP:
        match(OP);
        f_type = expr();
        match(CP);
        return f_type;
        break;
    case NOT:
        match(NOT);
        f_type = fctr(); //check
        f_type2 = notfn(f_type);
        return f_type2;
        break;
    case ID:
        f_tail_i = getType(tok);
        if (func == 1)
        {
            getParam(tok);
            //resType = f_tail_i;
            //strcpy(param, tok->parm);
            //func = 0;
            
        }
        match(ID);
        if((f_tail_i == 3 || f_tail_i == 4 || f_tail_i == 7 || f_tail_i == 8)) {
            if(tok->type != OB && eListCheck != 1) {
                fprintf(listing, "SEMERR: Array format incorrect. Need to follow the strucutre ArrayID[integer] ");
                    while (tok->type != ENDFILE && tok->type != MULOP && tok->type != ASSIGNOP && tok->type != ADDOP && tok->type != RELOP && tok->type != SEMICOLON && tok->type != END && tok->type != DO && tok->type != THEN && tok->type != CB && tok->type != COMMA && tok->type != CP && tok->type != ELSE)

                {
                    tok = gettoken();
                }
                errReturn = ERRSTARSTAR;
                return errReturn;
            }
        }
        if(func == 1) {
            func = 0;
            if(tok->type == SEMICOLON) {
                fprintf(listing, "SEMERR: Actual function parameters do not match formal parameters\n");
                f_type = ERR;
                return f_type;
            }
        }
        f_type = fctrTail(f_tail_i);
        return f_type; //check
        break;
    default:
        fprintf(listing, "SYNERR: Expecting num, ( , not, or id. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != MULOP && tok->type != ADDOP && tok->type != RELOP && tok->type != SEMICOLON && tok->type != END && tok->type != DO && tok->type != THEN && tok->type != CB && tok->type != COMMA && tok->type != CP && tok->type != ELSE)
        {
            tok = gettoken();
        }
        errReturn = ERRSTAR;
        return errReturn;
    }
    return ERR;
}

int termTail(int termTail_i)
{
    int t_type;
    int t_type2;
    int mulop_type;
    int f_type;
    int errReturn;
    switch (tok->type)
    {
    case MULOP:
        mulop_type = tok->types.att;
        match(MULOP);
        f_type = fctr();
        t_type2 = mulopErr(termTail_i, f_type);
        t_type = termTail(t_type2);
        return t_type;
        break;
    case ADDOP:
        t_type = termTail_i;
        return t_type;
        break;
    case RELOP:
        t_type = termTail_i;
        return t_type;
        break;
    case SEMICOLON:
        t_type = termTail_i;
        return t_type;
        break;
    case END:
        t_type = termTail_i;
        return t_type;
        break;
    case DO:
        t_type = termTail_i;
        return t_type;
        break;
    case THEN:
        t_type = termTail_i;
        return t_type;
        break;
    case CB:
        t_type = termTail_i;
        return t_type;
        break;
    case COMMA:
        t_type = termTail_i;
        return t_type;
        break;
    case CP:
        t_type = termTail_i;
        return t_type;
        break;
    case ELSE:
        t_type = termTail_i;
        return t_type;
        break;
    default:
        fprintf(listing, "SYNERR: Expecting mulop, addop, relop, ; ,  end, do, then, ] , , , ) , or else. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != ADDOP && tok->type != RELOP && tok->type != SEMICOLON && tok->type != END && tok->type != DO && tok->type != THEN && tok->type != CB && tok->type != COMMA && tok->type != CP && tok->type != ELSE)
        {
            tok = gettoken();
        }
        errReturn = ERRSTAR;
        return errReturn;
    }
    return ERR;
}

int term()
{
    int termTail_i;
    int term_type;

    switch (tok->type)
    {
    case NUM:
        termTail_i = fctr();
        term_type = termTail(termTail_i);
        return term_type;
        break;
    case OP:
        termTail_i = fctr();
        term_type = termTail(termTail_i);
        return term_type;
        break;
    case NOT:
        termTail_i = fctr();
        term_type = termTail(termTail_i);
        return term_type;
        break;
    case ID:
        termTail_i = fctr();
        term_type = termTail(termTail_i);
        return term_type;
        break;
    default:
        fprintf(listing, "SYNERR: Expecting num, ( , not, or id. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != ADDOP && tok->type != RELOP && tok->type != SEMICOLON && tok->type != END && tok->type != DO && tok->type != THEN && tok->type != CB && tok->type != COMMA && tok->type != CP && tok->type != ELSE)
        {
            tok = gettoken();
        }
        term_type = ERRSTAR;
        return term_type;
    }
    return ERR;
}

int sexprTail(int sexprTail_i)
{
    int sexprTail_type;
    int sexpr_type2;
    int addop_type;
    int t_type;
    switch (tok->type)
    {
    case ADDOP:
        //addop_type = tok->types.att;
        match(ADDOP);
        t_type = term();
        sexpr_type2 = addopErr(sexprTail_i, t_type);
        sexprTail_type = sexprTail(sexpr_type2);
        return sexprTail_type;
        break;
    case RELOP:
        sexprTail_type = sexprTail_i;
        return sexprTail_type;
        break;
    case SEMICOLON:
        sexprTail_type = sexprTail_i;
        return sexprTail_type;
        break;
    case END:
        sexprTail_type = sexprTail_i;
        return sexprTail_type;
        break;
    case DO:
        sexprTail_type = sexprTail_i;
        return sexprTail_type;
        break;
    case THEN:
        sexprTail_type = sexprTail_i;
        return sexprTail_type;
        break;
    case CB:
        sexprTail_type = sexprTail_i;
        return sexprTail_type;
        break;
    case COMMA:
        sexprTail_type = sexprTail_i;
        return sexprTail_type;
        break;
    case CP:
        sexprTail_type = sexprTail_i;
        return sexprTail_type;
        break;
    case ELSE:
        sexprTail_type = sexprTail_i;
        return sexprTail_type;
        break;
    default:
        fprintf(listing, "SYNERR: Expecting addop, relop, ; ,  end, do, then, ] , , , ) , or else. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != RELOP && tok->type != SEMICOLON && tok->type != END && tok->type != DO && tok->type != THEN && tok->type != CB && tok->type != COMMA && tok->type != CP && tok->type != ELSE)
        {
            tok = gettoken();
        }
        sexprTail_type = ERRSTAR;
        return sexprTail_type;
    }
    return ERR;
}

int sexpr()
{
    int sexprTail_i;
    int sexpr_t;
    int term_t;
    int errReturn;
    switch (tok->type)
    {
    case NUM:
        sexprTail_i = term();
        sexpr_t = sexprTail(sexprTail_i);
        return sexpr_t;
        break;
    case OP:
        sexprTail_i = term();
        sexpr_t = sexprTail(sexprTail_i);
        return sexpr_t;
        break;
    case NOT:
        sexprTail_i = term();
        sexpr_t = sexprTail(sexprTail_i);
        return sexpr_t;
        break;
    case ID:
        sexprTail_i = term();
        sexpr_t = sexprTail(sexprTail_i);
        return sexpr_t;
        break;
    case PLUS:
        sign();
        term_t = term();
        sexprTail_i = signfn(term_t);
        sexpr_t = sexprTail(sexprTail_i);
        return sexpr_t;
        break;
    case MINUS:
        sign();
        term_t = term();
        sexprTail_i = signfn(term_t);
        sexpr_t = sexprTail(sexprTail_i);
        return sexpr_t;
        break;
    default:
        fprintf(listing, "SYNERR: Expecting num, ( ,  not, id, +, or -. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != RELOP && tok->type != SEMICOLON && tok->type != END && tok->type != DO && tok->type != THEN && tok->type != CB && tok->type != COMMA && tok->type != CP && tok->type != ELSE)
        {
            tok = gettoken();
        }
        errReturn = ERRSTAR;
        return errReturn;
    }
    return ERR;
}

int exprTail(int exprTail_i)
{
    int exprTail_t;
    int sexpr_t;
    int errReturn;
    switch (tok->type)
    {
    case RELOP:
        match(RELOP);
        sexpr_t = sexpr();
        exprTail_t = relopfn(exprTail_i, sexpr_t);
        return exprTail_t;
        break;
    case SEMICOLON:
        exprTail_t = exprTail_i;
        return exprTail_t;
        break;
    case END:
        exprTail_t = exprTail_i;
        return exprTail_t;
        break;
    case DO:
        exprTail_t = exprTail_i;
        return exprTail_t;
        break;
    case THEN:
        exprTail_t = exprTail_i;
        return exprTail_t;
        break;
    case CB:
        exprTail_t = exprTail_i;
        return exprTail_t;
        break;
    case COMMA:
        exprTail_t = exprTail_i;
        return exprTail_t;
        break;
    case CP:
        exprTail_t = exprTail_i;
        return exprTail_t;
        break;
    case ELSE:
        exprTail_t = exprTail_i;
        return exprTail_t;
        break;
    default:
        fprintf(listing, "SYNERR: Expecting relop, ; ,  end, do, then, ] , , , ) , or else. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != SEMICOLON && tok->type != END && tok->type != DO && tok->type != THEN && tok->type != CB && tok->type != COMMA && tok->type != CP && tok->type != ELSE)
        {
            tok = gettoken();
        }
        errReturn = ERRSTAR;
        return errReturn;
    }
    return ERR;
}

int expr()
{
    int expr_t;
    int sexpr_i;
    int errReturn;
    switch (tok->type)
    {
    case NUM:
        sexpr_i = sexpr();
        expr_t = exprTail(sexpr_i);
        return expr_t;
        break;
    case OP:
        sexpr_i = sexpr();
        expr_t = exprTail(sexpr_i);
        return expr_t;
        break;
    case NOT:
        sexpr_i = sexpr();
        expr_t = exprTail(sexpr_i);
        return expr_t;
        break;
    case ID:
        sexpr_i = sexpr();
        expr_t = exprTail(sexpr_i);
        return expr_t;
        break;
    case PLUS:
        sexpr_i = sexpr();
        expr_t = exprTail(sexpr_i);
        return expr_t;
        break;
    case MINUS:
        sexpr_i = sexpr();
        expr_t = exprTail(sexpr_i);
        return expr_t;
        break;
    default:
        fprintf(listing, "SYNERR: Expecting num, (, not, id, +, or - . Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != SEMICOLON && tok->type != END && tok->type != DO && tok->type != THEN && tok->type != CB && tok->type != COMMA && tok->type != CP && tok->type != ELSE)
        {
            tok = gettoken();
        }
        errReturn = ERRSTAR;
        return errReturn;
    }
    return ERR;
}

int elistTail()
{
    int expr_t;
    int elistTail_t;
    int elistTail_i;
    int combinedParam;
    int errReturn;
    //char test[10];
    //int i = 1;
    switch (tok->type)
    {
    case COMMA:
        match(COMMA);
        expr_t = expr();
        
        if (expr_t == REAL)
        {
            expr_t = FUNPREAL;
        }
        else if (expr_t == INTEGER)
        {
            expr_t = FUNPINT;
        }
        else if (expr_t == AREAL)
        {
             expr_t = FUNPAREAL;
        }
        else if (expr_t == AINT)
        {
            expr_t = FUNPAINT;
        }
        else if (expr_t == INTNUM)
        {

            expr_t = FUNPINT;
        }
        else if (expr_t == REALNUM)
        {

            expr_t = FUNPREAL;
        }
        else if(expr_t == ERRSTAR) {

            while (tok->type != ENDFILE && tok->type != CP)
        {
            tok = gettoken();
        }

            return ERRSTAR; //change to get SEMERR
            //break;
        }
        elistOutput = concat(elistOutput, expr_t);
        elistTail_t = elistTail();
        
        return elistTail_t;
        break;
    case CP:
        break;
    default:
        fprintf(listing, "SYNERR: Expecting comma or ) . Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != CP)
        {
            tok = gettoken();
        }
        errReturn = ERRSTAR;
        return errReturn;
    }
    //return ERR;
}

//function calls
//each green node has a profile
int elist()
{
    int elist_t;
    int elistTail_i;
    int expr_t;
    int errReturn;
    int eListTail_t;
    switch (tok->type)
    {
    case NUM:
        elistOutput = expr();
        if(elistOutput == ERRSTAR) {
            return ERRSTAR;
            break;
        }
        if (elistOutput == REAL)
        {
            elistOutput = FUNPREAL;
        }
        else if (elistOutput == INTEGER)
        {
            elistOutput = FUNPINT;
        }
        else if (elistOutput == AREAL)
        {
            elistOutput = FUNPAREAL;
        }
        else if (elistOutput == AINT)
        {
            elistOutput = FUNPAINT;
        }
        else if (elistOutput == REALNUM)
        {
            elistOutput = FUNPREAL;
        }
        else if (elistOutput == INTNUM)
        {
            elistOutput = FUNPINT;
        }
        else if(elistOutput == ERRSTAR) {

            while (tok->type != ENDFILE && tok->type != CP)
        {
            tok = gettoken();
        }

            return ERRSTAR; //change to get SEMERR
            //break;
        }
        eListTail_t = elistTail();
        return eListTail_t;
        break;
    case CP:
        elistOutput = expr();
        if (elistOutput == REAL)
        {
            elistOutput = FUNPREAL;
        }
        else if (elistOutput == INTEGER)
        {
            elistOutput = FUNPINT;
        }
        else if (elistOutput == AREAL)
        {
            elistOutput = FUNPAREAL;
        }
        else if (elistOutput == AINT)
        {
            elistOutput = FUNPAINT;
        }
        else if (elistOutput == REALNUM)
        {
            elistOutput = FUNPREAL;
        }
        else if (elistOutput == INTNUM)
        {
            elistOutput = FUNPINT;
        }
        eListTail_t = elistTail();
        return eListTail_t;
        break;
    case NOT:
        elistOutput = expr();
        if (elistOutput == REAL)
        {
            elistOutput = FUNPREAL;
        }
        else if (elistOutput == INTEGER)
        {
            elistOutput = FUNPINT;
        }
        else if (elistOutput == AREAL)
        {
            elistOutput = FUNPAREAL;
        }
        else if (elistOutput == AINT)
        {
            elistOutput = FUNPAINT;
        }
        else if (elistOutput == REALNUM)
        {
            elistOutput = FUNPREAL;
        }
        else if (elistOutput == INTNUM)
        {
            elistOutput = FUNPINT;
        }
        eListTail_t = elistTail();
        return eListTail_t;
        break;
    case ID:
        elistOutput = expr();
        if (elistOutput == REAL)
        {
            elistOutput = FUNPREAL;
        }
        else if (elistOutput == INTEGER)
        {
            elistOutput = FUNPINT;
        }
        else if (elistOutput == AREAL)
        {
            elistOutput = FUNPAREAL;
            //elistOutput = FUNPREAL;
        }
        else if (elistOutput == AINT)
        {
            elistOutput = FUNPAINT;
            //elistOutput = FUNPINT;
        }
        else if (elistOutput == REALNUM)
        {
            elistOutput = FUNPREAL;
        }
        else if (elistOutput == INTNUM)
        {
            elistOutput = FUNPINT;
        }
        else if(elistOutput == ERRSTAR) {

            while (tok->type != ENDFILE && tok->type != CP)
        {
            tok = gettoken();
        }

            return ERRSTAR; //change to get SEMERR
            //break;
        }
        eListTail_t = elistTail();
        return eListTail_t;
        break;
    case PLUS:
        elistOutput = expr();
        if (elistOutput == REAL)
        {
            elistOutput = FUNPREAL;
        }
        else if (elistOutput == INTEGER)
        {
            elistOutput = FUNPINT;
        }
        else if (elistOutput == AREAL)
        {
            elistOutput = FUNPAREAL;
        }
        else if (elistOutput == AINT)
        {
            elistOutput = FUNPAINT;
        }
        else if (elistOutput == REALNUM)
        {
            elistOutput = FUNPREAL;
        }
        else if (elistOutput == INTNUM)
        {
            elistOutput = FUNPINT;
        }
        eListTail_t = elistTail();
        return eListTail_t;
        break;
    case MINUS:
        elistOutput = expr();
        if (elistOutput == REAL)
        {
            elistOutput = FUNPREAL;
        }
        else if (elistOutput == INTEGER)
        {
            elistOutput = FUNPINT;
        }
        else if (elistOutput == AREAL)
        {
            elistOutput = FUNPAREAL;
        }
        else if (elistOutput == AINT)
        {
            elistOutput = FUNPAINT;
        }
        else if (elistOutput == REALNUM)
        {
            elistOutput = FUNPREAL;
        }
        else if (elistOutput == INTNUM)
        {
            elistOutput = FUNPINT;
        }
        eListTail_t = elistTail();
        return eListTail_t;
        break;
    default:
        fprintf(listing, "SYNERR: Expecting num, ), not, id, +, or - . Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != CP)
        {
            tok = gettoken();
        }
        errReturn = ERRSTAR;
        return errReturn;

    }
}

int variableTail(int variableTail_i)
{
    int variableTail_t;
    int expr_t;
    int arrErr_t;
    int errReturn;
    switch (tok->type)
    {
    case OB:
        match(OB);
        expr_t = expr();
        match(CB);
        arrErr_t = arrayErr(variableTail_i, expr_t);
        return arrErr_t;
        break;
    case ASSIGNOP:
        if(variableTail_i == 3 || variableTail_i == 4 || variableTail_i == 7 || variableTail_i == 8) {
                if(tok->type != OB && eListCheck != 1) {
                    fprintf(listing, "SEMERR: Array format incorrect. Need to follow the strucutre ArrayID[integer] ");
                    while (tok->type != ENDFILE && tok->type != ASSIGNOP)
                    {
                        tok = gettoken();
                    }
                    errReturn = ERRSTARSTAR;
                    return errReturn;
                }
            }
        
        variableTail_t = variableTail_i;
        return variableTail_t;
        break;
    default:
        fprintf(listing, "SYNERR: Expecting [ or Assignop. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != ASSIGNOP)
        {
            tok = gettoken();
        }
        errReturn = ERRSTAR;
        return errReturn;
    }
    return ERR;
}

int variable()
{
    int var_t;
    int variableTail_i;
    int errReturn;
    switch (tok->type)
    {
    case ID:
        variableTail_i = getType(tok);
        match(ID);
        var_t = variableTail(variableTail_i);
        return var_t;
        break;
    default:
        fprintf(listing, "SYNERR: Expecting ID. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != ASSIGNOP)
        {
            tok = gettoken();
        }
        errReturn = ERRSTAR;
        return errReturn;
    }
    return ERR;
}

void stmtTail() //check
{
    switch (tok->type)
    {
    case ELSE:
        match(ELSE);
        stmt();
        break;
    case SEMICOLON:

        break;
    case END:

        break;
    //case ELSE:
    //
    default:
        fprintf(listing, "SYNERR: Expecting else , ; , or end. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != SEMICOLON && tok->type != END && tok->type != ELSE)
        {
            tok = gettoken();
        }
    }
}

int stmt()
{
    int expr_t;
    int ifErr_t;
    int whileErr_t;
    int stmt_t;
    int var_t;
    int retType;
    int errReturn;
    switch (tok->type)
    {
    case ID:
        var_t = variable();
        match(ASSIGNOP);
        expr_t = expr();
        retType = stmtErr(var_t, expr_t);
        return retType;
        break;
    case BEGIN:
        cstmt();
        stmt_t = OK;
        return stmt_t;
        break;
    case WHILE:
        match(WHILE);
        expr_t = expr();
        whileErr_t = whileErr(expr_t);
        match(DO);
        stmt();
        return whileErr_t;
        break;
    case IF:
        match(IF);
        expr_t = expr();
        ifErr_t = ifErr(expr_t);
        match(THEN);
        stmt();
        stmtTail();
        return ifErr_t;
        break;
    default:
        fprintf(listing, "SYNERR: Expecting ID , begin, while or if. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != SEMICOLON && tok->type != END && tok->type != ELSE)
        {
            tok = gettoken();
        }
        errReturn = ERRSTAR;
        return errReturn;
    }
    return ERR;
}

void slistTail()
{
    switch (tok->type)
    {
    case SEMICOLON:
        match(SEMICOLON);
        stmt();
        slistTail();
        break;
    case END:

        break;
    default:
        fprintf(listing, "SYNERR: Expecting ; or end. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != END)
        {
            tok = gettoken();
        }
    }
}

void slist()
{
    switch (tok->type)
    {
    case ID:
        stmt();
        slistTail();
        break;
    case BEGIN:
        stmt();
        slistTail();
        break;
    case WHILE:
        stmt();
        slistTail();
        break;
    case IF:
        stmt();
        slistTail();
        break;
    default:
        fprintf(listing, "SYNERR: Expecting ID, begin, while, or if. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != END)
        {
            tok = gettoken();
        }
    }
}

void ostmts()
{
    switch (tok->type)
    {
    case ID:
        slist();
        break;
    case BEGIN:
        slist();
        break;
    case WHILE:
        slist();
        break;
    case IF:
        slist();
        break;
    default:
        fprintf(listing, "SYNERR: Expecting ID, begin, while, or if. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != END)
        {
            tok = gettoken();
        }
    }
}

void cstmtTail()
{
    switch (tok->type)
    {
    case ID:
        ostmts();
        match(END);
        break;
    case BEGIN:
        ostmts();
        match(END);
        break;
    case WHILE:
        ostmts();
        match(END);
        break;
    case IF:
        ostmts();
        match(END);
        break;
    case END:
        match(END);
        break;
    default:
        fprintf(listing, "SYNERR: Expecting ID, begin, while, if, or end. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != DOT && tok->type != SEMICOLON && tok->type != END && tok->type != ELSE)
        {
            tok = gettoken();
        }
    }
}

void cstmt()
{
    switch (tok->type)
    {
    case BEGIN:
        match(BEGIN);
        cstmtTail();
        break;
    default:
        fprintf(listing, "SYNERR: Expecting begin . Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != DOT && tok->type != SEMICOLON && tok->type != END && tok->type != ELSE)
        {
            tok = gettoken();
        }
    }
}

void plistTail()
{
    switch (tok->type)
    {
    case SEMICOLON:
        match(SEMICOLON);
        if (tok->type == ID)
        {
            strcpy(lex2, tok->lex);
            t = 2;
        }
        match(ID);
        match(COLON);
        type();
        plistTail();
        break;
    case CP:

        break;
    default:
        fprintf(listing, "SYNERR: Expecting ; or ) . Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != CP)
        {
            tok = gettoken();
        }
    }
}
//just do offset for local variables(global variable)
//plist create profile
//plist can be 0, but each function much return at least one thing
void plist()
{
    switch (tok->type)
    {
    case ID:
        if (tok->type == ID)
        {
            strcpy(lex2, tok->lex);
            t = 2;
        }
        match(ID);
        match(COLON);
        type();
        plistTail();
        break;
    default:
        fprintf(listing, "SYNERR: Expecting ID. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != CP)
        {
            tok = gettoken();
        }
    }
}

void args()
{
    switch (tok->type)
    {
    case OP:
        match(OP);
        plist();
        match(CP);
        break;
    default:
        fprintf(listing, "SYNERR: Expecting ( . Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != COLON)
        {
            tok = gettoken();
        }
    }
}

void sheadTail()
{
    switch (tok->type)
    {
    case OP:
        args();
        match(COLON);
        break;
    case COLON:
        match(COLON);
        break;
    default:
        fprintf(listing, "SYNERR: Expecting ( or : . Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != BEGIN && tok->type != FUNCTION && tok->type != VAR)
        {
            tok = gettoken();
        }
    }
}

void shead()
{
    switch (tok->type)
    {
    case FUNCTION:
        match(FUNCTION);
        offset = 0;
        if (tok->type == ID)
        {
            createGreenNode(tok->lex, FUNNAME);
        }
        match(ID);
        sheadTail();
        funType = 1;
        stype();
        funType = 0;
        match(SEMICOLON);

        break;
    default:
        fprintf(listing, "SYNERR: Expecting Function. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != BEGIN && tok->type != FUNCTION && tok->type != VAR)
        {
            tok = gettoken();
        }
    }
}

void sdecTailTail()
{
    switch (tok->type)
    {
    case BEGIN:
        cstmt();
        popGreenNode();
        //pop
        break;
    case FUNCTION:
        sdecs();
        cstmt();
        popGreenNode();
        //pop
        break;
    default:
        fprintf(listing, "SYNERR: Expecting Begin or Function. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != SEMICOLON)
        {
            tok = gettoken();
        }
    }
}

void sdecTail()
{
    switch (tok->type)
    {
    case BEGIN:
        cstmt();
        popGreenNode();
        //pop
        break;
    case FUNCTION:
        sdecs();
        cstmt();
        decs();
        sdecTailTail();
        popGreenNode();
        //pop
        break;
    case VAR:
        decs();
        sdecTailTail();
        break;
    default:
        fprintf(listing, "SYNERR: Expecting Begin, Function, or Var. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != SEMICOLON)
        {
            tok = gettoken();
        }
    }
}

void sdec()
{
    switch (tok->type)
    {
    case FUNCTION:
        shead();
        sdecTail();
        break;
    default:
        fprintf(listing, "SYNERR: Expecting Function. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != SEMICOLON)
        {
            tok = gettoken();
        }
    }
}

void sdecsTail()
{
    switch (tok->type)
    {
    case FUNCTION:
        sdec();
        match(SEMICOLON);
        sdecsTail();
        break;
    case BEGIN:

        break;
    default:
        fprintf(listing, "SYNERR: Expecting Function or Begin. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != BEGIN)
        {
            tok = gettoken();
        }
    }
}

void sdecs() //start of
{
    switch (tok->type)
    {
    case FUNCTION:
        sdec();
        match(SEMICOLON);
        sdecsTail();
        break;
    default:
        fprintf(listing, "SYNERR: Expecting Function. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != BEGIN)
        {
            tok = gettoken();
        }
    }
}

int stype()
{
    int stdtype_t;
    switch (tok->type)
    {
    case INTEGER:
        stdtype_t = INTEGER;
        if (funType == 1)
        {
            updateGreenNode();
            nodeList->resType = stdtype_t;
            getGreenBack();
        }
        match(INTEGER);
        return stdtype_t;
        break;
    case REAL:
        stdtype_t = REAL;
        if (funType == 1)
        {
            updateGreenNode();
            nodeList->resType = stdtype_t;
            getGreenBack();
        }
        match(REAL);
        return stdtype_t;
        break;
    default:
        fprintf(listing, "SYNERR: Expecting INTEGER or Real. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != SEMICOLON && tok->type != CP)
        {
            tok = gettoken();
        }
    }
    return ERR;
}

int type()
{
    int num1;
    int num2;
    int type_t;
    int arrErr;
    int retType;
    int num1_t;
    int num2_t;
    switch (tok->type)
    {
    case INTEGER: //check
        type_t = stype();
        offset2 = 4;
        if (t == 1)
        {
            createBlueNode(lex2, INTEGER);
        }
        else if (t == 2)
        {
            createBlueNode(lex2, FUNPINT);
        }
        return type_t;
        break;
    case REAL:
        type_t = stype();
        offset2 = 8;
        if (t == 1)
        {
            createBlueNode(lex2, REAL);
        }
        else if (t == 2)
        {
            createBlueNode(lex2, FUNPREAL);
        }
        return type_t;
        break;
    case ARRAY:
        match(ARRAY);
        match(OB);
        if (tok->type == NUM)
        {
            num1 = atoi(tok->lex);
            num1_t = tok->types.att;
        }
        match(NUM); //check
        match(DOTDOT);
        if (tok->type == NUM)
        {
            num2 = atoi(tok->lex);
            num2_t = tok->types.att;
        }
        match(NUM);
        arrErr = arrayFun1(num1, num2, num1_t, num2_t);
        match(CB);
        match(OF);
        type_t = stype();
        retType = arrayFun2(arrErr, type_t, num1, num2);
        if (t == 1)
        {
            if (type_t == INTEGER)
            {
                createBlueNode(lex2, AINT);
            }
            else if (type_t == REAL)
            {
                createBlueNode(lex2, AREAL);
            }
        }
        else if (t == 2)
        {
            if (type_t == INTEGER)
            {
                createBlueNode(lex2, FUNPAINT);
            }
            else if (type_t == REAL)
            {
                createBlueNode(lex2, FUNPAREAL);
            }
        }
        return retType;
        break;
    default:
        fprintf(listing, "SYNERR: Expecting INTEGER, REAL, or ARRAY. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != SEMICOLON && tok->type != CP)
        {
            tok = gettoken();
        }
        //break;
    }
    return ERR;
}

void decsTail()
{
    int type_t;
    int tokType;
    switch (tok->type)
    {
    case VAR: //check
        match(VAR);
        if (tok->type == ID)
        {
            strcpy(lex2, tok->lex);
            tokType = tok->type;
            t = 1;
        }
        match(ID);
        match(COLON);
        type_t = type();
        if (type_t != ERR && tokType != LEXERR)
        {
            fprintf(address, "%s\tloc%d\n", lex2, offset);
            offset = offset + offset2;
            offset2 = 0;
        }
        match(SEMICOLON);
        decsTail();
        break;
    case FUNCTION:

        break;
    case BEGIN:

        break;
    default:
        fprintf(listing, "SYNERR: Expecting variable, function, or begin. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != FUNCTION && tok->type != BEGIN)
        {
            tok = gettoken();
        }
    }
}

void decs()
{
    int type_t;
    int decsTail_t;
    int tokType;
    switch (tok->type)
    {
    case VAR:
        match(VAR);
        if (tok->type == ID)
        {
            strcpy(lex2, tok->lex);
            tokType = tok->type;
            t = 1;
        }
        match(ID);
        match(COLON);
        type_t = type();
        if (type_t != ERR && tokType != LEXERR)
        {
            fprintf(address, "%s\tloc%d\n", lex2, offset);
            offset = offset + offset2;
            offset2 = 0;
        }
        match(SEMICOLON);
        decsTail();
        break;
    default:
        fprintf(listing, "SYNERR: Expecting variable. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != FUNCTION && tok->type != BEGIN)
        {
            tok = gettoken();
        }
    }
}

void idLstTail()
{
    switch (tok->type)
    {
    case COMMA:
        match(COMMA);
        if (tok->type == ID)
        {
            createBlueNode(tok->lex, PGMPARM);
        }
        match(ID);
        idLstTail();
        break;
    case CP:

        break;
    default:
        fprintf(listing, "SYNERR: Expecting , or ). Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != CP)
        {
            tok = gettoken();
        }
    }
}

void idLst()
{
    switch (tok->type)
    {
    case ID:
        if (tok->type == ID)
        {
            createBlueNode(tok->lex, PGMPARM);
        }
        match(ID);
        idLstTail();
        break;
    default:
        fprintf(listing, "SYNERR: Expecting ID. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE && tok->type != CP)
        {
            tok = gettoken();
        }
    }
}

void progTailTail()
{
    //listing = fopen("listing.txt", "w");
    switch (tok->type)
    {
    case FUNCTION:
        //offset = 0;
        sdecs();
        cstmt();
        match(DOT);
        break;
    case BEGIN:
        cstmt();
        match(DOT);
        break;
    default:
        fprintf(listing, "SYNERR: Expecting Function or Begin. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE)
        {
            tok = gettoken();
        }
    }
}

void progTail()
{
    //listing = fopen("listing.txt", "w");
    switch (tok->type)
    {
    case FUNCTION:
        offset = 0;
        sdecs();
        cstmt();
        match(DOT);
        break;
    case BEGIN:
        cstmt();
        match(DOT);
        break;
    case VAR:
        decs();
        progTailTail();
        break;
    default:
        fprintf(listing, "SYNERR: Expecting Function, Begin, or Var. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE)
        {
            tok = gettoken();
        }
    }
}

void prog()
{
    //listing = fopen("listing.txt", "w");
    switch (tok->type)
    {
    case PROG:
        match(PROG);
        if (tok->type == ID)
        {
            createGreenNode(tok->lex, PGMNAME);
        }
        match(ID);
        match(OP);
        idLst();
        match(CP);
        match(SEMICOLON);
        progTail();
        break;
    default:
        fprintf(listing, "SYNERR: Expecting program. Received %s\n", tok->tokenname);
        while (tok->type != ENDFILE)
        {
            tok = gettoken();
        }
    }
}

void parse()
{
    tok = gettoken();
    prog();
    match(ENDFILE);
}

int main()
{
    lastGreenNode = malloc(sizeof(token));
    address = fopen("address.txt", "w");
    listing = fopen("listing.txt", "w");
    tokenOutput = fopen("token.txt", "w");
    input = fopen("input.txt", "r");
    fgets(buffer, 72, input);
    ptr = buffer;
    reservedList();
    linkedId();
    parse();
}
