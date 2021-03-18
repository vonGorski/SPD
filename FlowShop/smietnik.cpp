
void sort_one_vector(vector<DATA>& data)
{
    sort(data.begin(), data.end());

}


void auto_sort_R(vector<DATA>& data)
{
    for (int j = 0; j < data.size() - 1; j++)
    {
        for (int i = 0; i < data.size() - j - 1; i++) {
            if (data[i].R < data[i + 1].R)
            {
                DATA temp = data[i + 1];
                data[i + 1] = data[i];
                data[i] = temp;

            }
        }
    }
}

void auto_sort_RP(vector<DATA>& data)
{
    for (int j = 0; j < data.size() - 1; j++)
    {
        for (int i = 0; i < data.size() - j - 1; i++) {
            if (data[i].RP < data[i + 1].RP)
            {
                DATA temp = data[i + 1];
                data[i + 1] = data[i];
                data[i] = temp;

            }
        }
    }
}

void auto_sort_PQ(vector<DATA>& data)
{
    for (int j = 0; j < data.size() - 1; j++)
    {
        for (int i = 0; i < data.size() - j - 1; i++) {
            if (data[i].PQ < data[i + 1].PQ)
            {
                DATA temp = data[i + 1];
                data[i + 1] = data[i];
                data[i] = temp;

            }
        }
    }

}

void auto_sort_Q(vector<DATA>& data)
{
    for (int j = 0; j < data.size() - 1; j++)
    {
        for (int i = 0; i < data.size() - j - 1; i++) {
            if (data[i].Q < data[i + 1].Q)
            {
                DATA temp = data[i + 1];
                data[i + 1] = data[i];
                data[i] = temp;

            }
        }
    }

}


void my_stiupid_algoritm_dont_work(vector<DATA>& data)
{
    vector<DATA>raw_data = data;
    // sortuje po najwiekszym RPQ
    sort_one_vector(raw_data);
    // wrzucam nawjiekszy na srodek
    data.push_back(raw_data[raw_data.size() - 1]);
    for (int i = raw_data.size() - 1; i >= 0; i--)
    {
        // wrzucam nawjiekszy na srodek
        data.push_back(raw_data[raw_data.size() - 1]);
        for (int i = raw_data.size() - 1; i >= 0; i--)
        {
            if (data[i].RP < data[i].PQ) data.insert(data.begin(), 1, raw_data[i]);
            else data.push_back(raw_data[i]);
        }

    }
}
