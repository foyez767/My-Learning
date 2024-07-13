 for (int i = 0; i < n; i++) {
        bool batti = true;

        for (int j = 1; j <= no_of_rounds[i]; j++) {
            cin >> score[i][j];

            if (score[i][j] < 0) {
                batti = false;
            }
        }
        disqualified_status[i] = batti;

        sort(score[i].begin(), score[i].end());
        partial_sum(score[i].begin(), score[i].end(), score[i].begin());

    }